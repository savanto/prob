#!/usr/bin/env python

"""
Pandigital multiples.
Problem 038

Take the number 192 and multiply it by each of 1, 2, and 3:

  192 * 1 = 192
  192 * 2 = 384
  192 * 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We
will call 192384576 the concatenated product of 192 and (1, 2, 3).

The same can be acheived by starting with 9 and multiplying by 1, 2, 3, 4,
and 5, giving the pandigital, 918273645, which is the concatenated product
of 9 and (1, 2, 3, 4, 5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as
the concatenated product of an integer with (1, 2, ..., n) where n > 1?
"""

def pandigital(pan):
  if len(pan) != 9:
    return False
  #         987654321
  check = 0b111111111
  for digit in pan:
    if digit == '0':
      return False
    check ^= 1 << (int(digit) - 1)
  return check == 0

MIN = 100000000
s = [1, 2]
for i in range(9876, 0, -1):
  pan = ""
  for n in s:
    pan += str(i * n)
  while int(pan) < MIN:
    s.append(s[-1] + 1)
    pan += str(i * s[-1])
  if pandigital(pan):
    print(i, " * (", ", ".join(str(j) for j in s), ") = ", pan, sep = '')
    break
