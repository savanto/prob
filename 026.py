#!/usr/bin/env python

"""
Reciprocal cycles.
Problem 026

A unit fraction contains 1 in the numerator. The decimal representation of the
unit fractions with denominators 2 to 10 are given:
    1/2 = 0.5
    1/3 = 0.(3)
    1/4 = 0.25
    1/5 = 0.2
    1/6 = 0.1(6)
    1/7 = 0.(142857)
    1/8 = 0.125
    1/9 = 0.(1)
    1/10 = 0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle
in its decimal fraction part.
"""

longest_cycle = 1
best_d = 1

for d in range(2, 1000):
  divs = []
  dec = []
  n = 1
  
  # Perform long division
  while n != 0 and n not in divs:
    divs.append(n)
    z = False
    while n < d:
      if z:
        dec.append(0)
        divs.append(n)
      n *= 10
      z = True
    q = n // d
    dec.append(q)
    n -= q * d

  # Only non-terminating fractions will have cycles
  if n != 0:
    cycle = len(divs) - divs.index(n)
    if cycle > longest_cycle:
      longest_cycle = cycle
      best_d = d

#    print("1/", d, " 0.", ''.join(str(i) for i in dec), " (", len(divs) - divs.index(n), ")", sep = '')
print("1/{0:d}".format(best_d), "(longest recurring cycle length = {0:d})".format(longest_cycle))
