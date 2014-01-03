#!/usr/bin/env python

"""
Number letter counts.
Problem 017

If the number 1 to 5 are written out in words: one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in
words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
letters. The use of "and" when writing out numbers is in compliance with
British usage.
"""

words = { 1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six",
    7: "seven", 8: "eight", 9: "nine", 10: "ten", 11: "eleven", 12: "twelve",
    13: "thirteen", 14: "fourteen", 15: "fifteen", 16: "sixteen",
    17: "seventeen", 18: "eighteen", 19: "nineteen", 20: "twenty", 30: "thirty",
    40: "forty", 50: "fifty", 60: "sixty", 70: "seventy", 80: "eighty",
    90: "ninety", 100: "hundred", 1000: "thousand" }

"""
FAILED ATTEMPT -- WHY?

# Ones: 1-9
ones = 0
for i in range(1, 10):
  ones += len(words[i])
# Tens: 1-99
tens = 0
for i in range(10, 20):
  tens += len(words[i])
for i in range(20, 91, 10):
  tens += len(words[i])
tens += ones * 8 + ones
# Hundreds: 1-999
hundreds = 0
for i in range(100, 901, 100):
  hundreds += (len(words[i // 100]) + len("hundred")) * 100
  hundreds += len("and") * 99
hundreds += tens * 9 + tens
# Thousand: 1000
thousand = len("one") + len("thousand")
thousand += hundreds

print(thousand)
"""

letters = 0
for i in range(1, 1000):
  h = i // 100
  r = i % 100
  if h != 0:
    #print(words[h], "hundred", end = ' ')
    letters += len(words[h]) + len("hundred")
    if r != 0:
      #print("and", end = ' ')
      letters += len("and")
  if r != 0:
    if r in words:
      #print(words[r], end = '')
      letters += len(words[r])
    else:
      t = r // 10
      r = r % 10
      #print(words[t*10], end = '')
      letters += len(words[t*10])
      if r != 0:
        #print("-", words[r], sep = '', end = '')
        letters += len(words[r])
#print("one thousand")
letters += len("one") + len("thousand")
print(letters)
