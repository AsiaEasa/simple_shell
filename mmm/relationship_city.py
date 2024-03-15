#!/usr/bin/python3

"""
    The module contains a Base and State class
"""

from sqlalchemy import Column, Integer, String, ForeignKey
from sqlalchemy.ext.declarative import declarative_base
from model_state import Base

Base = declarative_base()


class City(Base):
    """
    City class inherits the Base class
    """

    __tablename__ = "cities"

    id = Column(Integer,
                primary_key=True,
                nullable=False,
                autoincrement=True,
                unique=True)
    name = Column(String(128), nullable=False)
    state_id = Column(Integer, ForeignKey("states.id"), nullable=False)
