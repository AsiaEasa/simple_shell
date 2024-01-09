#!/usr/bin/python3
"""Defines a file-writing function."""


def write_file(filename="", text=""):
    """a string to a UTF8 text file.

    Args:
        filename (str): The name of the file to write.
        text (str): The text to write to the file.
    """
    with open(filename, "w", encoding="utf-8") as file1:
        return file1.write(text)
