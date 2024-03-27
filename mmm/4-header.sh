#!/bin/bash
# Script that takes in a URL as an argument, sends a GET request
curl -s -H "X-School-User-Id: 98" "$1"
