#!/usr/bin/python3
"""Defines a Pascal's Triangle function."""


def pascal_triangle(n):
    """Represent Pascal's Triangle of size n."""
    if n <= 0:
        return []

    t = [[1]]
    while len(t) != n:
        tri = t[-1]
        ptr = [1]
        for i in range(len(tri) - 1):
            ptr.append(tri[i] + tri[i + 1])
        ptr.append(1)
        t.append(ptr)
    return t
