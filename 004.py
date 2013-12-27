#!/usr/bin/env python

"""
Largest palindrome product
Problem 004

A palindromic number reads the same both ways. The largest palindrome made from
the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

import sys

P = 0
for a in range(999, 99, -1):
  for b in range(999, 99, -1):
    p = a * b
    if str(p) == str(p)[::-1]:
      if p > P:
        P = p
print(P)
