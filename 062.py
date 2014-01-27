#!/usr/bin/env python

"""
Cubic permutations.
Problem 062

The cube 41063625 (345^3), can be permuted to produce two other cubes:
56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest
cube which has exactly three permutations of its digits which are also
cubes.

Find the smallest cube for which exactly five permutations of its digits
are cubes.
"""

N = 5
CUBES = 10000

# Calculate some cubes
cubes = [i ** 3 for i in range(CUBES)]
for i in range(len(cubes)):
  cube = str(cubes[i])
  length = len(cube)
  digits = [0] * 10
  results = [ i ]
  for d in cube:
    digits[int(d)] += 1

  for j in range(i+1, len(cubes)):
    perm = str(cubes[j])
    if len(perm) > length:
      break
    perm_digits = [0] * 10
    for d in perm:
      perm_digits[int(d)] += 1
    if perm_digits == digits:
      results.append(j)
    if len(results) == N:
      break

  if len(results) == N:
    for r in results:
      print(r, "^3 = ", r ** 3, sep='')
    break
