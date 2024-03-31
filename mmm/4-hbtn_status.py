#!/usr/bin/python3
"""Python script that fetches url"""
import requests


if __name__ == "__main__":
    URL = 'https://alx-intranet.hbtn.io/status'
    response = requests.get(URL)

    print("Body response:")
    print("\t- type:", type(response.text))
    print("\t- content:", response.text)
