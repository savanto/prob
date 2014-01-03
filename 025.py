#!/usr/bin/env python

"""
1000-digit Fibonacci number.
Problem 025

The Fibonacci sequence is defined by the recurrence relation:

            Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:
            F1 = 1
            F2 = 1
            F3 = 2
            F4 = 3
            F5 = 5
            F6 = 8
            F7 = 13
            F8 = 21
            F9 = 34
            F10 = 55
            F11 = 89
            F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
"""

f1 = [1]
f2 = [1]
tmp = []
counter = 2
while len(f2) < 1000:
  carry = 0
  for i in range(len(f2)):
    if i < len(f1):
      s = f1[i] + f2[i] + carry
    else:
      s = f2[i] + carry
    carry = s // 10
    tmp.append(s % 10)
  if carry != 0:
    tmp.append(carry)
  f1 = f2
  f2 = tmp
  tmp = []
  counter += 1
print(counter)
