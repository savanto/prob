#!/usr/bin/env python

"""
Roman numerals.
Problem 089

The rules for writing Roman numerals allow for many ways of writing each
number. However, there is always a "best" way of writing a particular
number.

For example, the following represent all of the legitimate ways of writing
the number sixteen:

  IIIIIIIIIIIIIIII
  VIIIIIIIIIII
  VVIIIIII
  XIIIIII
  VVVI
  XVI

The last example being considered the most efficient, as it uses the least
number of numerals.

The 11K text file 089.txt contains one thousand numbers written in valid,
but not necessarily minimal, Roman numerals; that is, they are arranged in
descending units and obey the subtractive pair rule.

Find the number of characters saved by writing each of these in their
minimal form.

Note: you can assume that all Roman numerals in the file contain no more
than four consecutive identical units.
"""

ROMAN = { 'M': 1000, 'CM': 900, 'D': 500, 'CD': 400, 'C': 100, 'XC': 90,
          'L': 50, 'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1 }
DECIMAL = { 1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC',
            50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I' }
D = [ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ]

chars_old = 0
chars_new = 0

f = open("089.txt")
for roman in f:
  roman = roman.strip()
  chars_old += len(roman)

  # analyze roman numeral and convert to decimal
  decimal = d = 0
  for r in roman:
    if ROMAN[r] > d:
      decimal -= d * 2
    d = ROMAN[r]
    decimal += d

  # convert decimal to most efficient roman numeral representation
  roman = []
  for d in D:
    r = decimal // d
    roman += [ DECIMAL[d] * r ]
    decimal -= r * d
  chars_new += len(''.join(roman))

f.close()

print("Characters saved by writing all roman numerals in minimal form:",
    chars_old - chars_new)
