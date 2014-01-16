#!/usr/bin/env python

"""
Digit factorials.
Problem 034

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of
their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
"""

# Precalculate factorial look up table, since we need only 1! - 9!
# NB: 0! = 1
factorials = [1]
for i in range(1, 10):
  f = 1
  for j in range(i, 0, -1):
    f *= j
  factorials.append(f)

# Max from the fact that 7-digit 9999999 > 7 * 9!
fact_sum = 0
print("Digit factorials:")
for x in range(3, 2540160):
  digit_sum = sum(list(factorials[int(i)] for i in str(x)))
  if digit_sum == x:
    print(x)
    fact_sum += x
    x += 1
    f = 10
  elif digit_sum > x:
    x //= f
    x += 1
    x *= f
    f *= 10
  else:
    f = 10
    x += 1
print("Sum =", fact_sum)
