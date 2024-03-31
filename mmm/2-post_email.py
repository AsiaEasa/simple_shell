#!/usr/bin/python3
"""
Sends a POST request with an email parameter
and displays the body of the response.
"""

import urllib.parse
import urllib.request
import sys

if __name__ == "__main__":
    URL = sys.argv[1]
    email = sys.argv[2]

    D = urllib.parse.urlencode({'email': email}).encode('utf-8')
    REQ = urllib.request.Request(URL, D)

    with urllib.request.urlopen(REQ) as res:
        B = res.read().decode('utf-8')
        print(B)
