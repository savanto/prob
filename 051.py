#!/usr/bin/env python

"""
Prime digit replacements.
Problem 051

By replacing the 1st digit of the 2-digit number *3, it turns out that
six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all
prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this
5-digit number is the first example having seven primes among the ten
generated numbers, yielding the family: 56003, 56113, 56333, 56443,
56663, 56773, 56993. Consequently 56003, being the first member of this
family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not
necessarily adjacent digits) with teh same digit, is part of an eight
prime value family.
"""

from math import sqrt

def prime(n):
  if n % 2 == 0:
    return False
  for i in range(3, int(sqrt(n) + 1), 2):
    if n % i == 0:
      return False
  return True

target = 8
count = 0
i = 9
while count < target:
  i += 2
  if prime(i):
    s = str(i)
    l = len(s)
    digits = {}
    for d in range(l):
      digits[s[d]] = digits.get(s[d], []) + [d];
    for d, pos in digits.items():
      count = 0
      if len(pos) == 3:
        primes = []
        for j in range(10):
          x = list(s)
          for p in pos:
            x[p] = j
          p = int(''.join(str(k) for k in x))
          if len(str(p)) == l and prime(p):
            count += 1
            primes.append(p)
      if count >= target:
        break
print(' '.join(str(p) for p in primes))
