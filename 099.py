#!/usr/bin/env python

"""
Largest exponential.
Problem 099

Comparing two numbers written in index form like 2^11 and 3^7 is not
difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.

However, confirming that 632382^518061 > 519432^525806 would be much more
difficult, as both numbers contain over three million digits.

Using 099.txt, a 22K text file containing one thousand lines with a 
base/exponent pair on each line, determine which line number has the
greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example
given above.
"""

from math import log

f = open("099.txt")
max_base = 1
max_exp = 0
max_line = line_count = 0
for line in f:
  line_count += 1
  base, exp = [int(i) for i in line.strip().split(',')]
  if exp * log(base) > max_exp * log(max_base):
    max_base = base
    max_exp = exp
    max_line = line_count

print("Largest value {}^{} on line {}".format(max_base, max_exp, max_line))
