#!/usr/bin/python3
"""script that fetches"""
import urllib.request


def main():
    URL = 'https://alx-intranet.hbtn.io/status'

    REQ = urllib.request.Request(URL)

    with urllib.request.urlopen(REQ) as response:
        CON = response.read()
        print("Body response:")
        print("\t- type:", type(CON))
        print("\t- content:", CON)
        print("\t- utf8 content:", CON.decode('utf-8'))


if __name__ == "__main__":
    main()
