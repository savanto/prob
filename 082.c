/* Path sum: three ways.
 * Problem 082
 *
 * NOTE: This problem is a more challenging version of Problem 081.
 *
 * The minimal path sum in the 5 by 5 matrix below, by starting in any cell
 * in the left column and finishing in any cell in the right column, and
 * only moving up, down, and right, is indicated in red and bold; the sum
 * is equal to 994.
 * 
 *     131  673 (234)(103)( 18)
 *    (201)( 96)(342) 965  150
 *     630  803  746  422  111
 *     537  699  497  121  956
 *     805  732  524   37  331 
 *
 * Find the minimum path sum, in 082.txt, a 31K text file containing a
 * 80 by 80 matrix, from the left column to the right column.
 */

#include <stdlib.h>
#include <stdio.h>

#define N 5//80
#define INFILE "082.txt"

int main() {
  int i, j, k;

  // Test matrix from example
  int square[N][N] = { { 131, 673, 234, 103,  18 },
                       { 201,  96, 342, 965, 150 },
                       { 630, 803, 746, 422, 111 },
                       { 537, 699, 497, 121, 956 },
                       { 805, 732, 524,  37, 331 } };

  int uvd[N] = {0}; // Up vs down
  int uvr[N] = {0}; // Up vs right
  int dvr[N] = {0}; // Down vs right
  int min[N] = {0};

  for (j = N-2; j >= 0; --j) {
    for (i = 0; i < N; ++i) {
      if (i == 0) { // No move up
        // Up vs down
        uvd[i] = square[i][j] + square[i+1][j];
        // Up vs right
        uvr[i] = square[i][j] + square[i][j+1];
        // Down vs right
        dvr[i] = square[i][j] 
          + (square[i+1][j] < square[i][j+1] ? square[i+1][j] : square[i][j+1]);
      }
      else if (i == N-1) { // No move down
        // Up vs down
        uvd[i] = square[i][j] + square[i-1][j];
        // Up vs right
        uvr[i] = square[i][j] 
          + (square[i-1][j] < square[i][j+1] ? square[i-1][j] : square[i][j+1]);
        // Down vs right
        dvr[i] = square[i][j] + square[i][j+1];
      }
      else {
        // Up vs down
        uvd[i] = square[i][j] 
          + (square[i-1][j] < square[i+1][j] ? square[i-1][j] : square[i+1][j]);
        // Up vs right
        uvr[i] = square[i][j] 
          + (square[i-1][j] < square[i][j+1] ? square[i-1][j] : square[i][j+1]);
        // Down vs right
        dvr[i] = square[i][j] 
          + (square[i+1][j] < square[i][j+1] ? square[i+1][j] : square[i][j+1]);
      }
      min[i] = uvd[i] < uvr[i] ? uvd[i] : uvr[i];
      min[i] = min[i] < dvr[i] ? min[i] : dvr[i];
    }
    for (i = 0; i < N; ++i)
      square[i][j] = min[i];
    for (i = 0; i < N; ++i)
      printf("%d\n", square[i][j]);
    printf("\n");
  }


/*
  // Read real matrix in from file
  int square[N][N];
  char num[10], c;
  FILE* file = fopen(INFILE, "r");
  for (i = 0; i < N; ++i) {
    for (j = 0; j < N; ++j) {
      for (k = 0; k < 10; ++k)
        num[k] = 0;
      k = 0;
      c = fgetc(file);
      while (c != ',' && c != '\n' && c != EOF) {
        num[k++] = c;
        c = fgetc(file);
      }
      square[i][j] = atoi(num);
    }
  }
*/



//  fclose(file);
  return 0;
}
