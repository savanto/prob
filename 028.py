#!/usr/bin/env python

"""
Number spiral diagonals
Problem 028

Starting with the number 1 and moving to the right in a clockwise direction
a 5 by 5 spiral is formed as follows:

                           (21)22 23 24(25)
                            20 (7) 8 (9)10
                            19  6 (1) 2 11
                            18 (5) 4 (3)12
                           (17)16 15 14(13)

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
formed in the same way?
"""

# 1001x1001 => n = 1001
# Since n is odd, spiral will terminate in upper right corner at value n^2
# Diagonal 1: center <-> top-right (n^2)
# Diagonal 2: center <-> top-left (n^2 - n + 1)
# Diagonal 3: center <-> bot-left ((n-1)^2 + 1)
# Diagonal 4: center <-> bot-right ((n-1)^2 - n + 2)
diag_sum = 1
for i in range(3, 1002, 2):
  # Diag 1
  diag_sum += i ** 2
  # Diag 2
  diag_sum += i ** 2 - i + 1
  # Diag 3
  diag_sum += (i-1) ** 2 + 1
  # Diag 4
  diag_sum += (i-1) ** 2 - i + 2

print(diag_sum)
