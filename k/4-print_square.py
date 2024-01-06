#!/usr/bin/python3
"""Module for print_square method."""


def print_square(size):
    """Prints a square using the character #.
    Args: size (int): The size length of the square.
    """
    if not isinstance(size, int):
        raise TypeError("size must be an integer")

    if size < 0 or (isinstance(size, float) and size < 0):
        raise ValueError("size must be >= 0")

    for _ in range(size):
        print("#" * size)


if __name__ == "__main__":
    import doctest

    doctest.testfile("tests/4-print_square.txt")
