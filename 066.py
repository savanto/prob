#!/usr/bin/env python

"""
Diophantine equation.
Problem 066

Consider quadratic Diophantine equations of the form:

   x^2 - Dy^2 = 1

For example, when D = 13 the minimal solution in x is 649^2 - 13 * 180^2 = 1.

It can be assumed that there are no solutions in positive integers when D
is square.

By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the
following:

   3^2 - 2 * 2^2 = 1
   2^2 - 3 * 1^2 = 1
  (9)^2- 5 * 4^2 = 1
   5^2 - 6 * 2^2 = 1
   8^2 - 7 * 3^2 = 1

Hence, by considering minimal solutions in x for D <= 7, the largest x is
obtained when D = 5.

Find the value of D <= 1000 in minimal solutions of x for which the
largest value of x is obtained.
"""

from math import sqrt

D = 1000
max_x = 0
best_d = 0

# Solutions to Pell's equation are found by testing each successive convergent
# for sqrt(d).
for d in range(2, D+1):
  x = x0 = rem = rt = int(sqrt(d))
  y = y0 = 1;
  if rt ** 2 == d: # Skip perfect squares
    continue
  elif x ** 2 - d * y ** 2 == 1:  # Solution found with y = 1 */
    print(x, "^2 - ", d, " * ", y, "^2 = 1", sep='')
    if x > max_x:
      max_x = x
      best_d = d
  else:
    num = 1
    den = d - rem ** 2
    b = num * (rt + rem) // den
    rem = den * b - rem
    num = den
    den = d - rem ** 2
    x = x1 = b * x0 + 1
    y = y1 = b
    while x ** 2 - d * y ** 2 != 1:
      b = num * (rt + rem) // den
      num = den // num
      rem = num * b - rem
      den = d - rem ** 2
      x = b * x1 + 1 * x0
      y = b * y1 + 1 * y0
      x0 = x1
      y0 = y1
      x1 = x
      y1 = y
    print(x, "^2 - ", d, " * ", y, "^2 = 1", sep='')
    if x > max_x:
      max_x = x
      best_d = d
print("Largest x =", max_x, "when D =", best_d)
