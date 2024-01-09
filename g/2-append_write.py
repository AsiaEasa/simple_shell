#!/usr/bin/python3
"""Defines a file-appending function."""


def append_write(filename="", text=""):
    """Appends a string to the end of a UTF8 text
        filename (str): The name of the file to append to.
        text (str): The string to append to the file.
    """
    with open(filename, "a", encoding="utf-8") as file2:
        return file2.write(text)
