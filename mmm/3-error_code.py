#!/usr/bin/python3
"""Python script that takes in a URL"""
import sys
import urllib.request
import urllib.error


if __name__ == "__main__":
    URL = sys.argv[1]
    REQ = urllib.request.Request(URL)

    try:
        with urllib.request.urlopen(REQ) as res:
            B = res.read().decode('utf-8')
            print(B)
    except urllib.error.HTTPError as E:
        print(f"Error code: {E.code}")
