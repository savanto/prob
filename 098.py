#!/usr/bin/env python

"""
Anagramic squares.
Problem 098

By replacing each of the letters in the word CARE with 1, 2, 9, and 6
respectively, we form a square number: 1296 = 36^2. What is remarkable is that,
by using the same digital substitutions, the anagram, RACE, also forms a square
number: 9216 = 96^2. We shall call CARE (and RACE) a square anagram word pair
and specify further that leading zeroes are not permitted, neither may a
different letter have the same digital value as another letter.

Using 098.txt, a 16K text file containing nearly two-thousand common English
words, find all the square anagram word pairs (a palindromic word is NOT
considered to be an anagram of itself).

What is the largest square number formed by any member of such a pair?

NOTE: All anagrams formed must be contained in the given text file.
"""

import math

# Convert each word into an integer by specifying the number of times each
# letter appears at that letters position in the alphabet.
#              ZYXWVUTSRQPONMLKJIHGFEDCBA
# Ie. "CARE" = 00000000100000000000010101
#     "RACE" = 00000000100000000000010101
#   "EXCEPT" = 00100010001000000000020100
#   "EXPECT" = 00100010001000000000020100
words = {}
max_len = 0
with open("098.txt") as f:
  for word in f.read().strip().split(','):
    word = word[1:-1]
    if len(word) > max_len:
      max_len = len(word)
    i = 0
    for c in word:
      i += 10 ** (ord(c) - ord('A'))
    if i in words:
      words[i].append(word)
    else:
      words[i] = [word]

# For each anagram (more than one word encoded by key), pick a square with
# same number of digits as letters. Assign digits to letters.
# Check if rearranged digits (anagrams) also make a square.
max_squares = [ 0 ]
max_words = []
for anagrams in words.values():
  if len(anagrams) > 1:
    end = int(math.sqrt(10 ** (len(anagrams[0]) - 1)))
    start = int(math.sqrt(10 ** len(anagrams[0])))
    while start > end:
      square = start ** 2
      start -= 1
      squares = [ square ]
      words = [ anagrams[0] ]
      digits = {}
      letters = {}
      for c in anagrams[0][::-1]:
        d = square % 10
        if c in digits and digits[c] != d:
          break
        if d in letters and letters[d] != c:
          break
        digits[c] = d
        letters[d] = c
        square //= 10

      if square == 0:
        #print(digits)
        for word in anagrams[1:][::-1]:
          square = 0
          for c in word:
            square += digits[c]
            square *= 10
          square //= 10
          sqrt = math.sqrt(square)
          if sqrt == int(sqrt) and sqrt >= end:
            squares.append(square)
            words.append(word)

      if len(words) > 1:
        if squares[0] > max_squares[0]:
          max_squares = squares
          max_words = words
        break

for word, square in zip(max_words, max_squares):
  print(word, ': ', square, ' = ', int(math.sqrt(square)), '^2', sep='')
