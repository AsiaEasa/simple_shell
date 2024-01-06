#!/usr/bin/python3
"""
This module defines a function that prints the given first and last names.
Functions:
    say_my_name(first_name, last_name="").
"""


def say_my_name(first_name, last_name=""):
    """
    Prints My name is <first name> <last name>.
    """

    # Check if first_name is a string
    if not isinstance(first_name, str):
        raise TypeError("first_name must be a string")

    # Check if last_name is a string
    if not isinstance(last_name, str):
        raise TypeError("last_name must be a string")

    # Print the formatted message
    print("My name is {:s} {:s}".format(first_name, last_name))


if __name__ == "__main__":
    import doctest
    doctest.testfile("tests/3-say_my_name.txt")
