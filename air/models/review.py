#!/usr/bin/python3
"""This is the class for reviews"""

from models.base_model import BaseModel


class Review(BaseModel):
    """The base class of reviews"""
    place_id = ""
    user_id = ""
    text = ""
