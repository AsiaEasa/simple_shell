#!/usr/bin/python3
"""Defines a text file insertion function."""


def append_after(filename="", search_string="", new_string=""):
    """Insert text after each line"""
    txt = ""
    with open(filename) as file100:
        for line in file100:
            txt += line
            if search_string in line:
                txt += new_string
    with open(filename, "w") as file1:
        file1.write(txt)
