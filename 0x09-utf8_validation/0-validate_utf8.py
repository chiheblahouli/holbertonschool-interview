#!/usr/bin/python3
""" function  that determines a utf-8"""


def validUTF8(data):
    """
    data will represent multiples caracteres
    """
    num = 0
    for count in data:
        li = 1 << 7
        if num == 0:
            while li & count:
                num = num + 1
                li = li >> 1
            if num == 1 or num > 4:
                return False
            if num == 0:
                continue
        else:
            if (count >> 6) != 0b10:
                return False
        num = num - 1
    if num == 0:
        return True
    return False
