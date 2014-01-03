#!/usr/bin/env python

"""
Names scores.
Problem 022

Using 022.txt, a 46K text file containing over five-thousand first names, begin
by sorting it into alphabetical order. Then working out the alphabetical value
for each name, multiply this value by its alphabetical position in the list to
obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is
worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would
obtain a score of 938 * 53 = 49714.

What is the total of all the name scores in the file?
"""

names = open("022.txt").read().split(',')
names.sort()
conv = 64
total = 0
for i in range(len(names)):
  name = names[i][1:-1] # strip quotes
  score = 0
  for c in name:
    score += ord(c) - conv
  total += score * (i + 1)
print(total)
