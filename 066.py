#!/usr/bin/env python

"""
066
Problem 066


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
