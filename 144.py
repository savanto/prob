#!/usr/bin/env python

"""
Investigating multiple reflections of a laser beam.
Problem 144

In laser physics, a "white cell" is a mirror system that acts as a delay
line for the laser beam. The beam enters the cell, bounces around on the
mirrors, and eventually works its way back out.

The specific white cell we will be considering is an ellipse with the
equation 4x^2 + y^2 = 100.

The section corresponding to -0.01 <= x <= +0.01 at the top is missing,
allowing the light to enter and exit through the hole.

   [ See figure. ]

The light beam in this problem starts at the point (0.0, 10.1) just outside
the white cell, and the beam first impacts the mirror at (1.4, -9.6).

Each time the laser beam hits the surface of the ellipse, it follows the
usual law of reflection "angle of incidence equals angle of reflection."
That is, both the incident and reflected beams make the same angle with the
normal line at the point of incidence.

In the figure on the left, the red line shows the first two points of
contact between the laser beam and the wall of the white cell; the blue line
shows the line tangent to the ellipse at the point of incidence of the first
bounce.

The slope m of the tangent line at any point (x, y) of the given ellipse is:
m = -4x/y.

The normal line is perpendicular to this tangent line at the point of
incidence.

The animation on the right shows the first 10 reflections of the beam.

   [ See figure. ]

How many times does the beam hit the internal surface of the white cell
before exiting?
"""

##############################
## See 144.c for commentary ##
##############################
from math import tan, atan, sqrt
EPS = 0.000001

prev_x = 0.0
prev_y = 10.1
next_x = 1.4
next_y = -9.6

slope_beam = (prev_y - next_y) / (prev_x - next_x)
intrc_beam = prev_y

refls = 0
while (next_y < 9.99 or (next_x > 0.01 or next_x < -0.01)):
  refls += 1
  print("Reflection {} at ({}, {})".format(refls, next_x, next_y))
#  print("\ty = {}x + {}".format(slope_beam, intrc_beam))
  slope_tan  = -4 * next_x / next_y
  slope_norm = -1 / slope_tan
  slope_beam = tan(atan(slope_beam) + 2 * (atan(slope_norm) - atan(slope_beam)))
  intrc_beam = next_y - slope_beam * next_x
  A = 4 + slope_beam ** 2
  B = 2 * slope_beam * intrc_beam
  C = intrc_beam ** 2 - 100

  prev_x = next_x
  prev_y = next_y

  next_x = (sqrt(B ** 2 - 4 * A * C) - B) / (2 * A)
  if (abs(prev_x - next_x) <= EPS):
    next_x = (-sqrt(B ** 2 - 4 * A * C) - B) / (2 * A)
  next_y = sqrt(100 - 4 * next_x ** 2)
  if (abs((prev_y - next_y) / (prev_x - next_x) - slope_beam) > EPS):
    next_y = -sqrt(100 - 4 * next_x ** 2)

print("{} reflections, exit at ({}, {})".format(refls, next_x, next_y))
