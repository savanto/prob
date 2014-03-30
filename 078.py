#!/usr/bin/env python

"""
Coin partitions.
Problem 078

Let p(n) represent the number of different ways in which n coins can be
separated into piles. For example, five coins can be separated into piles in
exactly seven different ways, so p(5) = 7.

    OOOOO
    OOOO O
    OOO OO
    OOO O O
    OO OO O
    OO O O O
    O O O O O

Find the least value of n for which p(n) is divisible by one million.
"""

"""
The partition recurrence function is as follows:
  p(n) = p(n-1) + p(n-2) - p(n-5) - p(n-7) + p(n-12) + p(n-15) - p(n-22) - ...
  where p(0) = 1 and [p(n) for n < 0] = 0
The number subtracted from n are generalized pentagonal numbers, given by:
  m(3m - 1) / 2   for m = 0, +-1, +-2, +-3, ...
The sign for each term follows the pattern:
  +, +, -, -, +, +, -, -, ...
"""

# Start with the first two generalized pentagonal numbers, for m = +-1
# We will skip m = 0
k = [1, 2]
m = 2
# Start with the first two partition numbers, for n = 0, 1
p = [1, 1]
n = 1
# Partition numbers become huge quickly. We will take each one mod 1000000
# the goal is to find the first one divisible by 1000000.
t = 1000000

# We are storing the last 6 digits of each partition number, ie. p(n) % 1000000
# If the result is zero, we have found one that is divisible evenly by 1000000.
while p[n] != 0:
  n += 1
  # Generate generalized pentagonal numbers up to n, to be used in the partion
  # recurrence function later.
  while k[-1] <= n:
    k.append(m * (3 * m - 1) // 2)    # +m
    k.append(-m * (3 * -m - 1) // 2)  # -m
    m += 1
  pn = 0
  i = 0
  # Use values of k up to n; if k > n, then n - k < 0, and p(negative) = 0
  while k[i] <= n:
    # The sign is calculated by taking -1 to the power of
    # 0, 0, 1, 1, 0, 0, 1, 1, ...
    pn += p[n-k[i]] * (-1)**(i//2 % 2)
    i += 1
  # Append the last 6 digits of the next partition number to the list.
  p.append(pn % t)

print("Least value of n for which p(n) is divisible by {}: {}".format(t, n))
