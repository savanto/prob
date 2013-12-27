#!/usr/bin/env python

"""
10001st prime
Problem 007

By listing the first six prime numbers: 2, 3, 5, 7, 11, 13, we can see that the
6th prime is 13.

What is the 10001st prime number?
"""

primes = [2]

p = 3
while len(primes) != 10001:
  is_prime = True
  for prime in primes:
    if p % prime == 0:
      is_prime = False
      break
  if is_prime:
    primes.append(p)
  p += 2
print(primes[-1])
