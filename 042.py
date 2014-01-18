#!/usr/bin/env python

"""
Coded triangle numbers.
Problem 042

The nth term of the sequence of triangle numbers is given by tn = 1/2n(n+1);
so the first ten triangle numbers are:

  1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its
alphabetical position and adding these values we form a word value. For
example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word
value is a triangle number then we shall call the word a triangle word.

Using 042.txt, a 16K text file containing nearly two-thosand common English
words, how many are triangle words?
"""

# Assuming maximum word length of 20, composed of all Z's (value 26),
# the max score = 20 * 26 = 520
# Generate triangle numbers <= 528 (n = 32)
triangles = list((i * (i + 1)) // 2 for i in range(1, 33))

# Load words from file. Words are in the format "WORD1","WORD2", ...
try:
  with open("042.txt") as f:
    words = f.read().strip().split(',')
except:
  print("Unable to open file 042.txt")

twords = 0
scale = ord('A') - 1
# Score words
for word in words:
  score = 0
  for c in word[1:-1]:  # exclude the quotes surrounding word
    score += ord(c) - scale
  if score in triangles:
    twords += 1
print(twords, "triangle words in 042.txt")
