#!/usr/bin/python3
"""
rotate_2d_matrix
"""


def rotate_2d_matrix(matrix):
    """procedure to rotoate a giving matrix"""
    arr = list(map(list, matrix))

    l = len(matrix)
    for i in range(l):
        for j in range(l):
            matrix[i][j] = arr[l - j - 1][i]
