#!/usr/bin/python3
"""Solves the N-queens puzzle."""
import sys


def init_board(n):
    """Initialize an `n`x`n` sized chessboard with 0's."""
    bo = []
    bo = [[" " for _ in range(n)] for _ in range(n)]
    return bo


def board_deepcopy(bo):
    """Return a deepcopy"""
    if type(bo) is list:
        return list(map(board_deepcopy, bo))
    return bo


def get_solution(board):
    """Return the list of lists representation of a solved chessboard."""
    return [
        [r, c]
        for r in range(len(board))
        for c in range(len(board))
        if board[r][c] == "Q"
    ]


def xout(chessboard, row_played, col_played):
    """X out spots on a chessboard."""
    directions = [(1, 0), (-1, 0), (0, 1),
                  (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]

    for dr, dc in directions:
        r, c = row_played + dr, col_played + dc
        while 0 <= r < len(chessboard) and 0 <= c < len(chessboard):
            chessboard[r][c] = "x"
            r += dr
            c += dc


def recursive_solve(chessboard, current_row, queens_placed, result_solutions):
    """Recursively solve an N-queens puzzle."""
    if queens_placed == len(chessboard):
        result_solutions.append(get_solution(chessboard))
        return result_solutions

    for col in range(len(chessboard)):
        if chessboard[current_row][col] == " ":
            tmp_chessboard = board_deepcopy(chessboard)
            tmp_chessboard[current_row][col] = "Q"
            xout(tmp_chessboard, current_row, col)
            result_solutions = recursive_solve(
                tmp_chessboard, current_row + 1,
                queens_placed + 1, result_solutions
            )

    return result_solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = init_board(int(sys.argv[1]))
    solutions = recursive_solve(board, 0, 0, [])
    for sol in solutions:
        print(sol)
