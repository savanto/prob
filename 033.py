#!/usr/bin/env python

"""
Digit canceling fractions.
Problem 033

The fraction 49/98 is a curious fraction, as an inexperienced mathematician
in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less
than one in value, and containing two digits in the numerator and
denominator.

If the product of these four fractions is given in its lowest common terms,
find the value of the denominator.
"""

epsilon = 0.0001
print("Incorrect reductions:")
canceling_fractions = []
for d in range(11, 100):
  for n in range(10, d):
    # Split n and d into digits to see if they have any in common
    n_digits = tuple(int(i) for i in str(n))
    d_digits = tuple(int(i) for i in str(d))
    fracs = []
    if 0 in n_digits or 0 in d_digits:
      continue
    if n_digits[0] == d_digits[0]:
      fracs.append((n_digits[1], d_digits[1]))
    if n_digits[0] == d_digits[1]:
      fracs.append((n_digits[1], d_digits[0]))
    if n_digits[1] == d_digits[0]:
      fracs.append((n_digits[0], d_digits[1]))
    if n_digits[1] == d_digits[1]:
      fracs.append((n_digits[0], d_digits[0]))
    nd = n / d
    for f in fracs:
      if abs(nd - f[0] / f[1]) <= epsilon:
        print(n, '/', d, " = ", f[0], '/', f[1], sep = '')
        canceling_fractions.append((n, d))
N = 1
D = 1
for f in canceling_fractions:
  N *= f[0]
  D *= f[1]
print("Product of special fractions: ", N // N, '/', D // N, sep = '')
