#!/usr/bin/python3
"""
Displays the value of the X-Request-Id variable
found in the header of the response.
"""
import urllib.request
import sys


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ./1-hbtn_header.py <URL>")
        sys.exit(1)

    URL = sys.argv[1]

    with urllib.request.urlopen(URL) as res:
        x_request_id = res.headers.get('X-Request-Id')
        print(x_request_id)
