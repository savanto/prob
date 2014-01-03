#!/usr/bin/env python

"""
Counting Sundays.
Problem 019

You are given the following information, but you may prefer to do some research
for yourself.

  - 1 Jan 1900 was a Monday.
  - Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
  - A leap year occurs on any year evenly divisible by 4, but not a century
    unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century
(1 Jan 1901 to 31 Dec 2000)?
"""

months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

# Determine starting day of week on 1 Jan 1901
# 1900 is not special, so we can use maths
day = 365 % 7 # 0 => mon, 6 => sun
# Traverse months, checking if the first is a sunday
sundays = 0
for i in range(1901, 2001):
  for m in months:
    if day == 6:
      sundays += 1
    # Check for leap year
    if m == 28:
      if i % 400 == 0 or (i % 100 != 0 and i % 4 == 0):
        m += 1
    day = (m % 7 + day) % 7
print(sundays)
