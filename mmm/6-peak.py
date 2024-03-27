#!/usr/bin/python3
"""Find a peak in a list of unsorted integers."""


def find_peak(list_of_integers):
    """Find a peak in a list of unsorted integers."""
    if not list_of_integers:
        return None

    L = 0
    R = len(list_of_integers) - 1

    while L < R:
        M = L + (R - L) // 2

        if list_of_integers[M] < list_of_integers[M + 1]:
            L = M + 1
        else:
            R = M

    return list_of_integers[L]
