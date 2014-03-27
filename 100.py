#!/usr/bin/env python

"""
Arranged probability.
Problem 100

If a box contains twenty-one coloured discs, composed of fifteen blue discs and
six red discs, and two discs were taken at random, it can be seen that the
probability of taking two blue discs, P(BB) = (15/21) * (14/20) = 1/2.

The next such arrangement, for which there is exactly 50% chance of taking two
blue discs at random, is a box containing eighty-five blue discs and
thirty-five red discs.

By finding the first arrangement to contain over 10^12 = 1,000,000,000,000
discs in total, determine the number of blue discs that the box would contain.
"""

"""
Let b = # blue discs, t = total # of discs
  P(BB) = b/t * (b-1)/(t-1) = 1/2
  2b^2 - 2b = t^2 - t
  b^2 - b - 1/2t^2 + 1/2t = 0
This is a second-order Diophantine equation. Attempt to turn it into a Pell
equation of the form w^2 - Dz^2 = N.
Solve for b:
  b = (+-sqrt(1 - 4(-2t^2 + 2t)) + 1) / 2   (quadratic formula)
  b = (+-sqrt(1 + 2t^2 - 2t) + 1) / 2
Since term under radical must be integer, let:
  z^2 = 1 + 2t^2 - 2t
  b = (+-z + 1) / 2
Solve for t:
  2t^2 - 2t + 1 - z^2 = 0
  t^2 - t + (1 - z^2) / 2 = 0
  t = (+-sqrt(1 - 4(1 - z^2) / 2) + 1) / 2
  t = (+-sqrt(1 - 2 + 2z^2) + 1) / 2
Since term under radical must be integer, let:
  w^2 = 2z^2 - 1
  t = (+-w + 1) / 2
Now we have a Pell equation:
  w^2 - Dz^2 = N
  w^2 - 2z^2 = -1
This can be solved by testing successive convergents of sqrt(D) = sqrt(2):
  x = An/Bn = w/z
  x = b0 + a1 / (b1 + a2 / (b2 + a3 / (b3 + a4 / (b4 + ...))))
Convergents are computed as follows:
  sqrt(2) = 1 + 1 / (2 + 1 / (2 + 1 / (2 + 1 / (2 + ...))))
  b0 = 1; a1, a2, ..., an = 1
  b1, b2, ..., bn = 2
  x0 = A0/B0 = b0
  x1 = A1/B1 = (b1b0 + a1) / b1
  x2 = A2/B2 = (b2(b1b0 + a1) + a2b0) / (b2b1 + a2)
  xn = An/Bn = (bnAn-1 + anAn-2) / (bnBn-1 + anBn-2)
As each xn = w/z is computed, plug in w and z into the Pell equation above to
verify that w^2 - 2z^2 == -1.
If so, compute t = (w + 1) / 2.
We want the first t > 10^12.
Once this is found, b = (z + 1) / 2.
"""

# Compute continued fraction of sqrt(2)
b0 = an = 1
bn = 2

A0 = B0 = 1
A1 = (bn * b0 + an)
B1 = bn

#print("{}/{}".format(A0, B0))
#print("{}/{}".format(A1, B1))

# First t calculation, even if it doesn't satisfy Pell equation.
t = (A1 + 1) // 2

while t < 1000000000000:
  An = bn * A1 + an * A0
  Bn = bn * B1 + an * B0

  # Check that w^2 - 2z^2 = -1 is satisfied
  if An ** 2 - 2 * Bn ** 2 == -1:
    t = (An + 1) // 2

  A0 = A1
  A1 = An
  B0 = B1
  B1 = Bn

# First t above 10^12 has been found.
b = (Bn + 1) // 2
print("Blue: {} Red: {} Total: {}".format(b, t - b, t))
