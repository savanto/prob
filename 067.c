/* Maximum path sum II
 * Problem 067
 *
 * By starting at the top of the triangle below and moving to adjacent
 * numbers on the row below, the maximum total from top to bottom is 23.
 *
 *     (3)
 *    (7)4
 *   (2)4 6
 *   8 5(9)3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom in 067.txt, a 15K text file
 * containing a triangle with one-hundred rows.
 *
 * NOTE: This is a much more difficult version of Problem 018. It is not
 * possible to try every route to solve this problem, as there are 2^99
 * altogether! If you could check one trillion (10^12) routes every second
 * it would take over twenty billion years to check them all. There is an
 * efficient algorithm to solve it. ;o)
 */

#include <stdlib.h>
#include <stdio.h>

#define N 100
#define D 2

int main() {
  FILE* file = fopen("067.txt", "r");
  if (file == NULL)
    return 1;

  char num[D+2];  // 2 digits, 1 whitespace, \0
  unsigned long long triangle[N][N];
  int row, col;
  for (row = 0; row < N; ++row) {
    for (col = 0; col <= row; ++col) {
      fgets(num, D+2, file);
      triangle[row][col] = atoi(num);
    }
  }

  // Start on penultimate row
  unsigned long long right, left;
  for (row = N-2; row >= 0; --row) {
    for (col = 0; col <= row; ++col) {
      left = triangle[row][col] + triangle[row+1][col];
      right = triangle[row][col] + triangle[row+1][col+1];
      triangle[row][col] = (left > right ? left : right);
    }
  }
  printf("Max from top to bottom: %llu\n", triangle[0][0]);
  return 0;
}
