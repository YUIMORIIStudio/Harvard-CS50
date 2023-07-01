import os
import logging
from cs50 import SQL
from flask import (Flask, flash, redirect, render_template, request, send_file,
                   session)
from flask_session import Session
from helpers import apology, login_required, lookup, usd
from log import setup_logging
from werkzeug.security import check_password_hash, generate_password_hash

# Configure application
app = Flask(__name__)

logger = logging.getLogger(__name__)


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/logs")
def view_logs():
    log_file = "logs/app.log"  # Correct the path to the log file
    if os.path.exists(log_file):
        return send_file(log_file)
    else:
        return "Log file not found."


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# =================== index ====================
@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    try:
        stocks = db.execute(
            "SELECT symbol, name, price, SUM(shares) as totalShares FROM transactions WHERE user_id = ? GROUP BY symbol",
            user_id
        )

        cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        total = cash

        for stock in stocks:
            total += stock["price"] * stock["totalShares"]

        return render_template("index.html", stocks=stocks, cash=cash, usd=usd, total=total)

    except Exception as e:
        log.error(f"Error occurred while fetching stocks: {str(e)}")
        return apology("Something went wrong. Please try again later.")

# =================== buy ====================


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        stock = lookup(symbol)
        if not symbol:
            return apology("Please enter a symbol!")
        elif not stock:
            return apology("Invalid symbol!")
        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("Shares must be an integer!")
        if shares <= 0:
            return apology("Shares must be a positive integer!")

        user_id = session["user_id"]
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        stock_name = stock["name"]
        stock_price = stock["price"]
        total_price = stock_price * shares

        if cash < total_price:
            return apology("Not enough cash!")
        else:
            try:
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - total_price, user_id)
                db.execute("INSERT INTO transactions (user_id, name, shares, price, type, symbol) VALUES (?, ?, ?, ?, ?, ?)",
                           user_id, stock_name, shares, stock_price, 'buy', symbol)
                return redirect('/')
            except Exception as e:
                logger.error(f"Error occurred while buying shares: {str(e)}")
                return apology("Something went wrong. Please try again later.")
    else:
        return render_template("buy.html")

# =================== history ====================


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    # Pass the user_id as a tuple (user_id,) to the execute function
    transactions = db.execute("SELECT type, symbol, price, shares, time FROM transactions WHERE user_id = ?", (user_id,))
    return render_template("history.html", transactions=transactions, usd=usd)


# =================== login ====================#


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

# =================== logout ====================


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


# =================== quote ====================#


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Please enter a symbol")
        stock = lookup(symbol)
        if not stock:
            return apology("Invalid symbol!")
        return render_template("quoted.html", stock=stock, usd_function=usd)
    else:
        return render_template("quote.html")


# =================== register ====================#
@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    session.clear()

    if request.method == "POST":
        # Get the values from the form
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Validate form inputs
        if not username or not password or not confirmation:
            return apology("All fields are required!", 400)
        elif password != confirmation:
            return apology("Passwords do not match", 400)

        try:
            # Check if username already exists
            existing_user = db.execute("SELECT * FROM users WHERE username = ?", username)
            if existing_user:
                return apology("Username has already been registered!")

            # Insert new user into the database
            generated_hash = generate_password_hash(password)
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generated_hash)

            return redirect("/")
        except Exception as e:
            log.error(f"Error occurred while registering user: {str(e)}")
            return apology("Something went wrong. Please try again later.")
    else:
        return render_template("register.html")

# =================== sell ====================


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        user_id = session["user_id"]
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        if shares <= 0:
            return apology("Shares must be a positive number!")

        stock_price = lookup(symbol)["price"]
        stock_name = lookup(symbol)["name"]
        price = shares * stock_price

        shares_owned = db.execute(
            "SELECT shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol",
            user_id, symbol
        )[0]["shares"]

        if shares_owned < shares:
            return apology("You don't have enough shares!")

        current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        db.execute("UPDATE users SET cash = ? WHERE id = ? ", current_cash + price, user_id)
        db.execute(
            "INSERT INTO transactions(user_id, name, shares, price, type, symbol) VALUES(?,?,?,?,?,?)",
            user_id, stock_name, -shares, price, "sell", symbol
        )

        return redirect('/')

    else:
        user_id = session["user_id"]
        symbols = db.execute("SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
        return render_template("sell.html", symbols=symbols)