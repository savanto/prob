#!/usr/bin/env python

"""
Double-base palindromes.
Problem 036

The decimal number, 585 = 0b1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in
base 10 and base 2.

(Please note that the palindromic number, in either base, may not include
leading zeros.)
"""
palin_sum = 0
print("Double-base palindromes:")
for n in range(1000000):
  str_n = str(n)
  str_b = bin(n)[2:] # cut off "0b" prefix of binary
  if str_n == str_n[::-1] and str_b == str_b[::-1]:
    print(n, '=', bin(n))
    palin_sum += n
print("Sum of all double-base palindromes =", palin_sum)
