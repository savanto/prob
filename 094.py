#!/usr/bin/env python

"""
Almost equilateral triangles.
Problem 094

It is easily proved that no equilateral triangle exists with integral length
sides and integral area. However, the almost equilateral triangle 5-5-6 has an
area of 12 square units.

We shall define an almost equilateral triangle to be a triangle for which two
sides are equal and the third differs by no more than one unit.

Find the sum of the perimeters of all almost equilateral triangles with
integral side lengths and area and whose perimeters do not exceed one billion
(1,000,000,000)
"""

"""
      ^
     /|\
    / | \
 c /  |  \ c
  /   |   \
 /    |b   \
/     |     \
-------------
      2a
Looking for triangles where abs(2a - c) == 1.
These are composed of right triangles with sides a, b, c, which are 
Pythagorean triples.
Generate Pythagorean triples using the Euclid formula:
  Using pairs of positive integers m, n where m > n, m - n is odd, and m and n
  are coprime. This will give all primitive triples by the following formulas:
  a = m^2 - n^2, b = 2mn, c = m^2 + n^2
Then, test whether abs(2a - c) == 1 or abs(2b - c) == 1, and if so, 
add the perimieter of the triangle c-c-2{a,b} to the running sum.
"""

MAX_P = 1000000000
P = 0

n = 1
m = n + 1
a = m**2 - n**2
b = 2 * m * n
c = m**2 + n**2
pa = 2*a + 2*c
pb = 2*b + 2*c

print("Almost-equilateral triangles:")
while pa < MAX_P and pb < MAX_P:
  while pa < MAX_P and pb < MAX_P:
    if abs(2*a - c) == 1:
      print("{}-{}-{}".format(c, c, 2*a))
      P += pa
    elif abs(2*b - c) == 1:
      print("{}-{}-{}".format(c, c, 2*b))
      P += pb
    m += 2
    a = m**2 - n**2
    b = 2 * m * n
    c = m**2 + n**2
    pa = 2*a + 2*c
    pb = 2*b + 2*c
    
  n += 1
  m = n + 1
  a = m**2 - n**2
  b = 2 * m * n
  c = m**2 + n**2
  pa = 2*a + 2*c
  pb = 2*b + 2*c

print("Sum of perimieters of almost-equilateral triangles:", P)
