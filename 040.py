#!/usr/bin/env python

"""
Champernowne's constant.
Problem 040

An irrational decimal fraction is created by concatenating the positive
integers:

  0.12345678910(1)112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of
the following expression.

  d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000
"""

champ = ''.join(str(i) for i in range(1, 1000000))
p = 1
f = 1
while f <= 1000000:
  p *= int(champ[f-1])
  f *= 10
print(p)
