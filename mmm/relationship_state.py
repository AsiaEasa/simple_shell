#!/usr/bin/python3

"""
    The module contains a Base and State class
"""

from sqlalchemy import Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship
from relationship_city import Base, City

Base = declarative_base()


class State(Base):
    """
    State class inherits the Base class
    """

    __tablename__ = "states"

    id = Column(Integer, primary_key=True, nullable=False, autoincrement=True)
    name = Column(String(128), nullable=False)
    cities = relationship("City", backref="states")
