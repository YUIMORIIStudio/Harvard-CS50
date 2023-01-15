// import the dependencies
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Declare the variable to store the cents from the user
    int cents;
    do
    {
        cents = get_int("ENTER CHANGE OWED: ");
    } while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // Declare the variable to store the quarters from the user
    int getQuarters = 0;
    // check if there is room to acstract 25, then getQuarter++;
    while (cents >= 25)
    {
        getQuarters++;
        cents = cents - 25;
    }
    return getQuarters;
}

int calculate_dimes(int cents)
{
    // Declare the variable to store the dimes from the user
    int getDimes = 0;
    // check if there is room to acstract 10, then getQuarter++;
    while (cents >= 10)
    {
        getDimes++;
        cents = cents - 10;
    }
    return getDimes;
}

int calculate_nickels(int cents)
{
    // Declare the variable to store the nickles from the user
    int getNickels = 0;
    // check if there is room to acstract 5, then getNickels++;
    while (cents >= 5)
    {
        getNickels++;
        cents = cents - 5;
    }
    return getNickels;
}

int calculate_pennies(int cents)
{
    // Declare the variable to store the pennies from the user
    int getPennies = 0;
    // check if there is room to acstract 1, then getPennies++;
    while (cents >= 1)
    {
        getPennies++;
        cents = cents - 1;
    }
    return getPennies;
}
