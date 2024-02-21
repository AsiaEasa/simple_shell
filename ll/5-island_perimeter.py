#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island"""
    size = sum(row.count(1) for row in grid)
    edges = sum(
        (grid[i][j - 1] if j > 0 else 0) + (grid[i - 1][j] if i > 0 else 0)
        if grid[i][j] == 1 else 0
        for i in range(len(grid)) for j in range(len(grid[0]))
    )
    return size * 4 - edges * 2
