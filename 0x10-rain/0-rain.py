#!/usr/bin/python3
"""rain algo"""


def rain(walls):
    """calculation of rains"""
    rai = 0
    l = len(walls)
    if not walls or l < 3:
        return 0
    for i in range(1, l - 1):
        r = max(walls[i + 1:])
        b = max(walls[:i])
        mini = min(b, r)
        if walls[i] < mini:
            rai = rai + mini - walls[i]
    return rai
