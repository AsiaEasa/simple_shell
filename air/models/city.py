#!/usr/bin/python3
"""The models of city"""

from models.base_model import BaseModel


class City(BaseModel):
    """Class that every city will inhirit from"""
    state_id = ""
    name = ""
