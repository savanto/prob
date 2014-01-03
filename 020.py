#!/usr/bin/env python

"""
Factorial digit sum.
Problem 020

n! means n * (n - 1) * ... * 3 * 2 * 1
For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800, and the sum of the
digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27

Find the sum of the digits in the number 100!
"""

num = [1]
for i in range(1, 101):
  carry_1 = 0
  carry_10 = 0
  carry_100 = 0
  ones = i % 10
  tens = (i % 100) // 10
  hundreds = i // 100
  prod_1 = []
  prod_10 = [0]
  prod_100 = [0,0]
  for digit in range(len(num)):
    # ones
    prod = ones * num[digit] + carry_1
    if prod > 9:
      carry_1 = prod // 10
    else:
      carry_1 = 0
    prod_1.append(prod % 10)
    # tens
    prod = tens * num[digit] + carry_10
    if prod > 9:
      carry_10 = prod // 10
    else:
      carry_10 = 0
    prod_10.append(prod % 10)
    # hundreds
    prod = hundreds * num[digit] + carry_100
    if prod > 9:
      carry_100 = prod // 10
    else:
      carry_100 = 0
    prod_100.append(prod % 10)

  # addition
  num = [0 for i in range(len(prod_100))]
  carry = 0
  for i in range(len(prod_100)):
    num[i] = prod_100[i] + carry
    if i < len(prod_10):
      num[i] += prod_10[i]
    if i < len(prod_1):
      num[i] += prod_1[i]
    if num[i] > 9:
      carry = num[i] // 10
      num[i] %= 10
    else:
      carry = 0
print(sum(num))
