#!/usr/bin/env python

"""
Passcode derivation.
Problem 079

A common security method used for online banking is to ask the user for
three random characters from a passcode. For example, if the passcode was
531278, they may ask for the 2nd, 3rd, and 5th characters; the expected
reply would be: 317.

The text file 079.txt contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the
file so as to determine the shortest possible secret passcode of unknown
length.
"""

f = open("079.txt")
links = []
passcode = []
revcode = []

# create table of links, which numbers follow other numbers
for login in f:
  links.append((int(login[0]), int(login[1])))
  links.append((int(login[1]), int(login[2])))
f.close()

# find outgoing number which never has incoming link.
# this must be the first number of the passcode.
# Prune links table of entries with this number, then repeat process,
# as each time the outgoing number with no incoming link is next in pass
# Note: this may miss the last number of the passcode. For this reason,
# we find it as well and remember it.
while len(links) != 0:
  for i in range(10):
    outgoing = False
    incoming = False
    for out, inc in links:
      if out == i:
        outgoing = True
      if inc == i:
        incoming = True
    if outgoing and not incoming: # start of passcode
      passcode.append(i)
      links = [ link for link in links if link[0] != i ]
    elif incoming and not outgoing: # end of passcode
      revcode.append(i)

passcode.append(revcode[0])
print("The passcode:", ''.join(str(i) for i in passcode))
