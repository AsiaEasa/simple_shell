#!/usr/bin/python3
"""Module for matrix multiplication
"""


def matrix_mul(m_a, m_b):
    """Multiplies two matrices.
    Args:
        m_a (list of lists): First matrix.
        m_b (list of lists): Second matrix.
    Returns:
        list of lists: Result of the matrix multiplication."""

    if not isinstance(m_a, list):
        raise TypeError("m_a must be a list")
    if not isinstance(m_b, list):
        raise TypeError("m_b must be a list")

    for row in m_a:
        if not isinstance(row, list):
            raise TypeError("m_a must be a list of lists")

    for row in m_b:
        if not isinstance(row, list):
            raise TypeError("m_b must be a list of lists")

    m_a_nrect = False
    m_b_nrect = False
    m_a_nnum = False
    m_b_nnum = False

    for row in m_a:
        if len(row) != len(m_a[0]):
            m_a_nrect = True
        for num in row:
            if not isinstance(num, (int, float)):
                m_a_nnum = True

    for row in m_b:
        if len(row) != len(m_b[0]):
            m_b_nrect = True
        for num in row:
            if not isinstance(num, (int, float)):
                m_b_nnum = True

    if len(m_a) == 0 or (len(m_a) == 1 and len(m_a[0]) == 0):
        raise ValueError("m_a can't be empty")

    if len(m_b) == 0 or (len(m_b) == 1 and len(m_b[0]) == 0):
        raise ValueError("m_b can't be empty")

    if m_a_nnum:
        raise TypeError("m_a should contain only integers or floats")

    if m_b_nnum:
        raise TypeError("m_b should contain only integers or floats")

    if m_a_nrect:
        raise TypeError("each row of m_a must should be of the same size")

    if m_b_nrect:
        raise TypeError("each row of m_b must should be of the same size")

    if len(m_a[0]) != len(m_b):
        raise ValueError("m_a and m_b can't be multiplied")

    result = [
        [sum(a * b for a, b in zip(row_a, col_b)) for col_b in zip(*m_b)]
        for row_a in m_a
    ]
    return result


if __name__ == "__main__":
    import doctest
    doctest.testfile("tests/100-matrix_mul.txt")
