#!/usr/bin/env python

"""
Poker hands.
Problem 054

In the card game poker, a hand consists of five cards and are valueed, from
lowest to highest, in the following way:

  - High Card: Highest value card.
  - One Pair: Two cards of the same value.
  - Two Pairs: Two different pairs.
  - Three of a Kind: Three cards of the same value.
  - Straight: All cards are consecutive values.
  - Flush: All cards of the same suit.
  - Full House: Three of a kind and a pair.
  - Four of a Kind: Four cards of the same value.
  - Straight Flush: All cards are consecutive values of same suit.
  - Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
  2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same valueed hands then the value made up of the
hightest value wins; for example, a pair or eights beats a pair of fives
(see example 1 below). But if two values tie, for example, both players have
a pair of queens, then highest cards in each hand are compared (see example
4 below); if the highest cards tie then the next highest cards are compared,
and so on.

Consider the following five hands dealt to two players:

  Hand    Player 1          Player 2            Winner
  ------------------------------------------------------
    1     5H 5C 6S 7S KD    2C 3S 8S 8D TD      Player 2
          Pair of Fives     Pair of Eights

    2     5D 8C 9S JS AC    2C 5C 7D 8S QH      Player 1
          Highest card Ace  Highest card Queen

    3     2D 9C AS AH AC    3D 6D 7D TD QD      Player 2
          Three Aces        Flush with Diamonds

    4     4D 6S 9H QH QC    3D 6D 7H QD QS      Player 1
          Pair of Queens    Pair of Queens
          Highest card Nine Highest card Seven

    5     2H 2D 4C 4D 4S    3C 3D 3S 9S 9D      Player 1
          Full House        Full House
          With Three Fours  With Three Threes

The file 054.txt, contains one-thousand random hands dealt to two players.
Each line of the file contains ten cards (separated by a single space): the
first five are Player 1's cards and the last five are Player 2's cards. You
can assume that all hands are valid (no invalid characters or repeated
cards), each player's hand is in no specific order, and in each hand there
is a clear winner.

How many hands does Player 1 win?
"""

faces = { 'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14 };

class Hand(object):
  def __init__(self, cards):
    """
    cards -- a list of 5 tuples of the form (value, suit)
    """
    values = {}
    suits = {}
    self.values = []
    for val, suit in cards:
      values[val] = values.get(val, 0) + 1
      self.values.append(val)
      suits[suit] = suits.get(suit, 0) + 1
    
    self.values.sort()
    self.values.reverse()
    
    self.straightflush = 0
    self.quads = 0
    self.boat = 0
    self.flush = 0
    self.straight = 0
    self.set = 0
    self.pair = []
    
    # check for ranks
    if len(suits) == 1:
      self.flush = self.values[0]

    for val, count in values.items():
      if count == 4:
        self.quads = val
      elif count == 3:
        self.set = val
      elif count == 2:
        self.pair.append(val)
    self.boat = self.set if self.set != 0 and len(self.pair) == 1 else False
    self.pair.sort()
    self.pair.reverse()

    if len(values) == 5:
      self.straight = self.values[0]
      for i in range(1, 5):
        if self.values[i] != self.values[i-1] - 1:
          self.straight = 0
          break
      if self.values == [14, 5, 4, 3, 2]: # wheel
        self.straight = 5

    if self.straight and self.flush:
      self.straightflush = self.values[0]

  def __gt__(self, other):
    # Straight flush (including royal flush)
    if self.straightflush:
      if not other.straightflush:
        return True
      else:
        return self.straightflush > other.straightflush
    elif other.straightflush:
      return False

    # Four of a kind
    if self.quads:
      if not other.quads:
        return True
      else:
        return self.quads > other.quads
    elif other.quads:
      return False

    # Full house
    if self.boat:
      if not other.boat:
        return True
      else:
        return self.set > other.set
    elif other.boat:
      return False

    # Flush
    if self.flush:
      if not other.flush:
        return True
      else:
        return self.flush > other.flush
    elif other.flush:
      return False

    # Straight
    if self.straight:
      if not other.straight:
        return True
      else:
        return self.straight > other.straight
    elif other.straight:
      return False

    # Three of a kind
    if self.set:
      if not other.set:
        return True
      else:
        return self.set > other.set
    elif other.set:
      return False

    # Two pair
    if len(self.pair) == 2:
      if len(other.pair) != 2:
        return True
      elif self.pair[0] > other.pair[0]:
        return True
      elif self.pair[0] < other.pair[0]:
        return False
      else:
        if self.pair[1] > other.pair[1]:
          return True
        elif self.pair[1] < other.pair[1]:
          return False
        else:
          for i in range(5):
            if self.values[i] > other.values[i]:
              return True
            elif self.values[i] < other.values[i]:
              return False
    elif len(other.pair) == 2:
      return False

    # Pair
    if len(self.pair) == 1:
      if len(other.pair) != 1:
        return True
      elif self.pair[0] > other.pair[0]:
        return True
      elif self.pair[0] < other.pair[0]:
        return False
      else:
        for i in range(5):
          if self.values[i] > other.values[i]:
            return True
          elif self.values[i] < other.values[i]:
            return False
    elif len(other.pair) == 1:  
      return False

    # High card
    for i in range(5):
      if self.values[i] > other.values[i]:
        return True
      elif self.values[i] < other.values[i]:
        return False

    # Tie (not allowed)
    return False


try:
  with open("054.txt") as f:
    games = f.readlines();
except IOError:
  print("Could not open file 054.txt")

count = 0
for game in games:
  cards_s = game.split()
  cards = []
  for c in cards_s:
    if c[0] in "TJQKA":
      val = faces[c[0]]
    else:
      val = int(c[0])
    cards.append((val, c[1]))
  player1 = Hand(cards[:5])
  player2 = Hand(cards[5:])
  if player1 > player2:
    count += 1
print("Player 1 wins", count, "hands.")
