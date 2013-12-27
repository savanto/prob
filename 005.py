#!/usr/bin/env python

"""
Smallest multiple
Problem 005

2520 is the smallest number that can be divided by each of the numbers from
1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20?
"""

# All factors from 1 to 20. Numbers that have already appeared as products of
# smaller factors should not be reused.

#   1   2   3   4   5   6   7   8   9   10  11  12   13   14  15  16  17  18   19   20
p = 1 * 2 * 3 * 2 * 5 * 1 * 7 * 2 * 3 * 1 * 11 * 1 * 13 * 1 * 1 * 2 * 17 * 1 * 19 * 1
print(p)
