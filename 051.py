#!/usr/bin/env python

"""
051
Problem 051


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
