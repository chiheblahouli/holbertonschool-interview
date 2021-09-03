#!/usr/bin/python3
"""log"""


import sys


s = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0}
p = 0
size = 0
try:
    for line in sys.stdin:
        if p == 10:
            print("File size: {}".format(size))
            for k, v in sorted(s.items()):
                if v != 0:
                    print("{}: {}".format(k, v))
            p = 1
        else:
            p += 1
        split = line.split()
        if len(split) > 2:
            size += int(split[-1])
            for k, v in s.items():
                if split[-2] == k:
                    s[k] = s[k] + 1
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(size))
    for k, v in sorted(s.items()):
        if v != 0:
            print("{}: {}".format(k, v))
