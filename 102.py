#!/usr/bin/env python

"""
Triangle containment.
Problem 102

Three distinct points are plotted at random on a Cartesian plane, for which
-1000 <= x, y <= 1000, such that triangle is formed.

Consider the following two triangles:

  A(-340, 495), B(-153, -910), C(835, -947)
  X(-175,  41), Y(-421, -714), Z(574, -645)

It can be verified that triangle ABC contains the origin, whereas triangle XYZ
does not.

Using 102.txt, a 27K text file containing the co-ordinates of one thousand
"random" triangles, find the number of triangles for which the interior
contains the origin.

NOTE: The first two examples in the file represent the triangles in the example
given above.
"""

def cross(a, b):
  """
  Returns a x b, the cross product of the vectors a and b.
  """
  ai, aj = a
  bi, bj = b
  return ai * bj - aj * bi


triangles = []
num = 0
with open("102.txt") as f:
  for line in f.readlines():
    # Using 'Same sides technique' from
    # http://www.blackpawn.com/texts/pointinpoly/
    ai, aj, bi, bj, ci, cj = [int(i) for i in line.strip().split(',')]
    # Compute vectors AB, AC, AO
    AB = (bi - ai, bj - aj)
    AC = (ci - ai, cj - aj)
    AO = (0 - ai, 0 - aj)
    # AB x AO will have same sign as AB x AC if origin is on the same side of
    #   AB as point C.
    if cross(AB, AO) * cross(AB, AC) < 0:
      continue
    # Compute vectors BC, BA, BO
    BC = (ci - bi, cj - bj)
    BA = (ai - bi, aj - bj)
    BO = (0 - bi, 0 - bj)
    # BC x BO will have same sign as BC x BA if origin is on the same side of
    #   BC as point A.
    if cross(BC, BO) * cross(BC, BA) < 0:
      continue
    # Compute vectors CA, CB, CO
    CA = (ai - ci, aj - cj)
    CB = (bi - ci, bj - cj)
    CO = (0 - ci, 0 - cj)
    # CA x CO will have same sign as CA x CB if origin is on the same side of
    #   CA as point B.
    if cross(CA, CO) * cross(CA, CB) < 0:
      continue

    # Origin is on same side of AB as C, same side of BC as A, and same side of
    #   CA as B, so it must be within the triangle.
    num += 1

print("Triangles containing the origin:", num)
