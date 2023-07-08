from flask import Blueprint, render_template, request
from data_science_meetup_blog.models import BlogPost

core = Blueprint('core', __name__)

DEFAULT_PAGE = 1
POSTS_PER_PAGE = 10

@core.route('/')
def index():
    page = request.args.get('page', DEFAULT_PAGE, type=int)
    blog_posts = BlogPost.query.order_by(BlogPost.date.desc()).paginate(page=page, per_page=POSTS_PER_PAGE)
    return render_template('index.html', blog_posts=blog_posts)

@core.route('/info')
def info():
    return render_template('info.html')
