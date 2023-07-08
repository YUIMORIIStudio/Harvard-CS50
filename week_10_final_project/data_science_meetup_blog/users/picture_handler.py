#users/picture_handler.py
"""_summary_: This file contains the picture handler for the users blueprint.
The purpose of this code is to save a user's uploaded profile picture (pic_upload) to a static folder on the server under the profile picture directory (static/profile_pics) and to return the saved file name.
"""

import os
from PIL import Image
from flask import current_app

def add_profile_pic(pic_upload, username):

    filename = pic_upload.filename
    # "mypicture.jpg" -> "jpg"
    ext_type = filename.split('.')[-1]
    
    storage_filename = str(username) + '.' + ext_type

    filepath = os.path.join(current_app.root_path, 'static/profile_pics', storage_filename)
    output_size = (200, 200)


    pic = Image.open(pic_upload)
    pic.thumbnail(output_size)
    pic.save(filepath)

    return storage_filename




