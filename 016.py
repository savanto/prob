#!/usr/bin/env python

"""
Power digit sum.
Problem 016

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
"""

num = [1]
for power in range(1000):
  carry = 0
  for digit in range(len(num)):
    prod = num[digit] * 2 + carry
    if prod > 9:
      carry = prod // 10
      prod %= 10
    else:
      carry = 0
    num[digit] = prod
  if carry != 0:
    num.append(carry)

print(sum(num))
