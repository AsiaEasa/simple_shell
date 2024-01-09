#!/usr/bin/python3
"""Defines a Python class-to-JSON function."""


def class_to_json(obj):
    """dictionary represntation."""
    return obj.__dict__
