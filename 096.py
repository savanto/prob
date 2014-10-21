#!/usr/bin/env python

"""
Su Doku
Problem 096

Su Doku (Japanese meaning _number place_) is the name given to a popular puzzle
concept. Its origin is unclear, but credit must be attributed to Leonhard Euler
who invented a similar, and much more difficult, puzzle idea called Latin
Squares. The objective of Su Doku puzzles, however, is to replace the blanks
(or zeros) in a 9 by 9 grid in such a way that each row, column, and 3 by 3 box
contains each of the digits 1 to 9. Below is an example of a typical starting
puzzle grid and its solution grid.

  +-----+-----+-----+     +-----+-----+-----+
  |0 0 3|0 2 0|6 0 0|     |4 8 3|9 2 1|6 5 7|
  |9 0 0|3 0 5|0 0 1|     |9 6 7|3 4 5|8 2 1|
  |0 0 1|8 0 6|4 0 0|     |2 5 1|8 7 6|4 9 3|
  +-----+-----+-----+     +-----+-----+-----+
  |0 0 8|1 0 2|9 0 0|     |5 4 8|1 3 2|9 7 6|
  |7 0 0|0 0 0|0 0 8|     |7 2 9|5 6 4|1 3 8|
  |0 0 6|7 0 8|2 0 0|     |1 3 6|7 9 8|2 4 5|
  +-----+-----+-----+     +-----+-----+-----+
  |0 0 2|6 0 9|5 0 0|     |3 7 2|6 8 9|5 1 4|
  |8 0 0|2 0 3|0 0 9|     |8 1 4|2 5 3|7 6 9|
  |0 0 5|0 1 0|3 0 0|     |6 9 5|4 1 7|3 8 2|
  +-----+-----+-----+     +-----+-----+-----+

A well constructed Su Doku puzzle has a unique solution and can be solved by
logic, although it may be necessary to employ "guess and test" methods in order
to eliminate options (there is much contested opinion over this). The
complexity of the search determines the difficulty of the puzzle; the example
above is considered _easy_ because it can be solved by straight forward direct
deduction.

The 6K text file, 096.txt, contains fifty different Su Doku puzzles ranging in
difficulty, but all with unique solutions (the first puzzle in the file is the
example above).

By solving all fifty puzzles find the sum of the 3-digit numbers found in the
top left cornder of each solution grid; for example, 483 is the 3-digit number
found in the top left corner of the solution grid above.
"""

N = 2
D = 9
HR = "+-----+-----+-----+"

class Sudoku(object):
  def __init__(self, title, lines):
    self.title = title
    self.grid = []
    for line in lines:
      self.grid.append([ int(j) for j in line ])

  def __str__(self):
    out = [ self.title ]
    c = 0
    for line in self.grid:
      if c % 3 == 0: out.append(HR)
      c += 1
      out.append('|' + '|'.join([ ' '.join(str(i) for i in line[n:n+3])
        for n in range(0, 9, 3)]) + '|')
    out.append(HR)
    return '\n'.join(out)

  def valid_nums(self, row, col):
    if type(self.grid[row][col]) == int and self.grid[row][col] != 0:
      return True
    valid = []
    for i in range(1, 10):
      # Check row, col
      v = True
      for x in range(D):
        if self.grid[row][x] == i or self.grid[x][col] == i:
          v = False
          break
      if not v:
        continue
      # Check box
      R = row // 3 * 3
      C = col // 3 * 3
      for r in range(R, R + 3):
        for c in range(C, C + 3):
          if self.grid[r][c] == i:
            v = False

      if v:
        valid.append(i)

    if len(valid) == 0:
      self.grid[row][col] = -1
      return False
    elif len(valid) == 1:
      self.grid[row][col] = valid[0]
      return True
    else:
      self.grid[row][col] = valid
      return False

  def complete_nums(self):
    for i in range(D):
      unique_row = {}
      unique_col = {}
      for j in range(D):
        if type(self.grid[i][j]) == list:
          for p in self.grid[i][j]:
            if p not in unique_row:
              unique_row[p] = [ (i, j) ]
            else:
              unique_row[p].append( (i, j) )
        if type(self.grid[j][i]) == list:
          for p in self.grid[j][i]:
            if p not in unique_col:
              unique_col[p] = [ (j, i) ]
            else:
              unique_col[p].append( (j, i) )

      for p, coords in unique_row.items():
        if len(coords) == 1:
          r, c = coords[0]
          self.grid[r][c] = p
          return
      for p, coords in unique_col.items():
        if len(coords) == 1:
          r, c = coords[0]
          self.grid[r][c] = p
          return

    for i in range(3):
      for j in range(3):
        unique_box = {}
        for r in range(i * 3, (i + 1) * 3):
          for c in range(j * 3, (j + 1) * 3):
            if type(self.grid[r][c]) == list:
              for p in self.grid[r][c]:
                if p not in unique_box.items():
                  unique_box[p] = [ (r, c) ]
                else:
                  unique_box[p].append( (r, c) )

        for p, coords in unique_box:
          if len(coords) == 1:
            r, c = coords[0]
            self.grid[r][c] = p
            return


with open("096.txt") as f:
  for i in range(N):
    n = f.readline().strip()
    lines = []
    for line in range(D):
      lines.append(f.readline().strip())

    sudoku = Sudoku(n, lines)
    all_valid = False
    while not all_valid:
      all_valid = True
      for row in range(D):
        for col in range(D):
          if not sudoku.valid_nums(row, col):
            all_valid = False

      if not all_valid:
        sudoku.complete_nums()
      #all_valid = True
    print(sudoku)
