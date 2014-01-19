#!/usr/bin/env python

"""
Powerful digit sum
Problem 056

A googol (10^100) is a massive number: one followed by one-hundred zeros;
100^100 is almost unimaginably large: one followed by two-hundred zeros.
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the
maximum digital sum?
"""

max_sum = 0
max_a = 1
max_b = 1
for a in range(1, 100):
  for b in range(1, 100):
    s = sum(int(i) for i in str(a ** b))
    if s > max_sum:
      max_sum = s
      max_a = a
      max_b = b
print("{}^{} yields a digital sum of {}".format(max_a, max_b, max_sum))
