#!/usr/bin/env python

"""
Square root digital expansion.
Problem 080

It is well known that if the square of a natural number is not an integer,
then it is irrational. The decimal expansion of such square roots is
infinite without any repeating pattern at all.

The square root of two is 1.41421356237309504880..., and the digital sum of
the first one hundred decimal digits is 475.

For the first one hundred natural numbers, find the total of the digital
sums of the first one hundred decimal digits for all the irrational square
roots.
"""

LIMIT = 100
DIGITS = 100

digital_sum = 0

# perfect squares lookup table
perfect_square = [False] * LIMIT
for n in range(10):
  perfect_square[n*n] = True

for n in range(LIMIT):
  if not perfect_square[n]: # skip perfect squares
    # Perform digit-by-digit calculation of square root
    p = 0
    c = n

    for digits in range(DIGITS):
      x = y = 0
      while (y <= c):
        x += 1
        y = x * (20 * p + x)
      x -= 1
      y = x * (20 * p + x)
      c = (c - y) * 100
      p = p * 10 + x
      digital_sum += x

print("Sum of first {} digits of all irrational square roots below {} = {}"
    .format(DIGITS, LIMIT, digital_sum))
