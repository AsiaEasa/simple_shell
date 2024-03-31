#!/usr/bin/python3
"""
Sends a POST request with email parameter to the given URL
and displays the body of the response.
"""
import requests
import sys


if __name__ == "__main__":
    URL = sys.argv[1]
    email = sys.argv[2]

    P = {'email': email}
    res = requests.post(URL, data=P)

    print(res.text)
