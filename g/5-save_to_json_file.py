#!/usr/bin/python3
"""Defines a JSON file-writing function."""
import json


def save_to_json_file(my_obj, filename):
    """ using JSON ."""
    with open(filename, "w") as file5:
        json.dump(my_obj, file5)
