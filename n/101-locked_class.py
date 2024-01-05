#!/usr/bin/python3
"""Module a locked class."""


class LockedClass:
    """
    Prevent the user from instantiating new LockedClass attributes"""

    __slots__ = ["first_name"]
