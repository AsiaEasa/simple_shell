#!/usr/bin/python3
"""Models of a user"""

from models.base_model import BaseModel


class User(BaseModel):
    """The user that will inhereit from the base class"""
    email = ""
    password = ""
    first_name = ""
    last_name = ""
