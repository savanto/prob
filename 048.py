#!/usr/bin/env python

"""
Self powers.
Problem 048

The series 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series 1^1 + 2^2 + 3^3 + ... + 1000^1000.
"""

# Brute force approach, since python can handle the large numbers.
K = 10000000000
sum = 0
for i in range(1, 1001):
  prod = 1
  for j in range(i):
    prod = prod * i
  sum += prod
print(sum % K)
