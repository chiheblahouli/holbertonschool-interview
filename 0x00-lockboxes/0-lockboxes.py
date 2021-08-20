#!/usr/bin/python3
"""0-lockboxes"""


def canUnlockAll(boxes):
    """ i can do all """
    if len(boxes) == 0:
        return False
    if not isinstance(boxes, list):
        return False
    else:
        lenbox = len(boxes)
    arr = [0]
    j = 0
    for i in arr:
        try:
            for j in boxes[i]:
                if isinstance(j, int):
                    if j < lenbox and j not in arr and j != 0 and j is not i:
                        arr.append(j)
        except BaseException:
            pass
    return len(arr) == lenbox
