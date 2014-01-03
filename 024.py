#!/usr/bin/env python

"""
Lexicographic permutations
Problem 024

A permutation is an ordered arrangement of objects. For example, 3124 is one
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
are listed numerically or alphabetically, we call it lexicographic order. The
lexicographic permutations of 0, 1 and 2 are:

                  012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5,
6, 7, 8 and 9?
"""

import sys

# Permutations will be in lexicographic order already, because input was sorted
def perm(nset, prefix = [], perms = []):
  if len(nset) == 0:
    # Only gather permutations up to the millionth.
    # Had off-by-one error for some reason, so adjusted to 1000000 - 1
    # TODO figure out why
    if len(perms) == 1000000 - 1:
      print(''.join(str(i) for i in prefix))
      sys.exit(0)
    perms.append(prefix)
  else:
    for i in range(len(nset)):
      perm(nset[:i] + nset[i+1:], prefix + nset[i:i+1], perms)

perm([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
