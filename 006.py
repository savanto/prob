#!/usr/bin/env python

"""
Sum square difference
Problem 006

The sum of the squares of the first ten natural numbers is,
    1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
    (1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.
"""

# Sum of squares: a^2 + b^2 + c^2 + ... + n^2
# Square of sum:  (a + b + c + ... + n)^2 =
#   = a^2 + b^2 + c^2 + ... + n^2
#     + 2ab + 2ac + ... + 2an + 2bc + ... + 2bn + ... + 2cn + ... + 2(n-1)n
# So, (sum of squares) - (square of sum) =
#   = 2(ab + ac + ... + an + bc + ... + bn + ... + cn + ... + (n-1)n)
p = 0
for a in range(1, 101):
  for b in range(a + 1, 101):
    p += a * b
print(p * 2)
