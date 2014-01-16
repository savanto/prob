#!/usr/bin/env python

"""
Pandigital products.
Problem 032

We shall say that an n-digit number is pandigital if it makes use of all the
digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
through 5 pandigital.

The product 7254 is unusual, as the identity, 39 * 186 = 7254, containing
multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity
can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only
include it once in your sum.
"""

def pandigital(a, b, prod):
  #         987654321
  check = 0b111111111
  digits = list(str(a)) + list(str(b)) + list(str(prod))
  for d in digits:
    if int(d) == 0:
      return False
    check ^= 1 << (int(d) - 1)
  return check == 0

a = 1
b = 100
products = set()
prod = a * b
while prod < 10000:
  while prod < 10000:
    if pandigital(a, b, prod):
      print(a, '*', b, '=', prod)
      products.add(prod)
    b += 1
    prod = a * b
  a += 1
  b = 100
  prod = a * b
print("Sum of UNIQUE pandigital products =", sum(products))
