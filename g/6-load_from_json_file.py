#!/usr/bin/python3
"""Defines a JSON function."""
import json


def load_from_json_file(filename):
    """Create object from a JSON"""
    with open(filename) as file6:
        return json.load(file6)
