#!/usr/bin/python3
"""
This module defines a function that adds two integers.
Functions:
    add_integer(a, b=98): Adds two integers.
"""


def add_integer(a, b=98):
    """
    Adds two integers.
    """
    # Check if a is an integer or float
    if not isinstance(a, (int, float)):
        raise TypeError("a must be an integer")

    # Check if b is an integer or float
    if not isinstance(b, (int, float)):
        raise TypeError("b must be an integer")

    # Cast a and b to integers
    a = int(a)
    b = int(b)

    # Return the sum of a and b
    return a + b


if __name__ == "__main__":
    import doctest
    doctest.testfile("tests/0-add_integer.txt")
