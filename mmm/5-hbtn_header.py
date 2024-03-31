#!/usr/bin/python3
"""
Displays the value of the X-Request-Id variable
found in the header of the response.
"""
import sys
import requests


if __name__ == "__main__":
    URL = sys.argv[1]
    res = requests.get(URL)

    H = res.headers.get("X-Request-Id")
    print(H)
