/* Path sum: two ways.
 * Problem 081
 *
 * In the 5 by 5 matrix below, the minimal path sum from the top left to the
 * bottom right, by *only moving to the right and down*, is indicated in
 * bold red and is equal to 2427.
 *
 *    (131) 673  234  103   18
 *    (201)( 96)(342) 965  150
 *     630  803 (746)(422) 111
 *     537  699  497 (121) 956
 *     805  732  524 ( 37)(331)
 *
 * Find the minimum path sum, in 081.txt, a 31K text file containing a
 * 80 by 80 matrix, from the top left to the bottom right by only moving
 * right and down.
 */

#include <stdio.h>

#define N 80
#define INFILE "081.txt"

int main() {
  int i, j, k;

  // Test matrix from example
/*
  int square[N][N] = { { 131, 673, 234, 103,  18 },
                       { 201,  96, 342, 965, 150 },
                       { 630, 803, 746, 422, 111 },
                       { 537, 699, 497, 121, 956 },
                       { 805, 732, 524,  37, 331 } };
*/

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

  // Algorithm based on RudyPenteado's posted in the forum for problem 081.
  // 1. Go to SE corner
  // 2. Work vertically up accumulating values. Return.
  // 3. Work horizontally left accumulating values. Return.
  // 4. Move NW one step.
  // 5. Work vertically up adding min(E, S). Return.
  // 6. Work horizontally left adding min(E, S). Return.
  // 7. Repeat 4-6 until at NW corner.
  for (i = N-1, k = N-2; k >= 0; --k) {
    square[k][i] += square[k+1][i];
    square[i][k] += square[i][k+1];
  }

  for (i = N-2; i >= 0; --i) {
    square[i][i] += (square[i][i+1] < square[i+1][i] ? square[i][i+1] :
                                                       square[i+1][i]);
    for (k = i-1; k >= 0; --k) {
      square[k][i] += (square[k][i+1] < square[k+1][i] ? square[k][i+1] :
                                                         square[k+1][i]);
      square[i][k] += (square[i+1][k] < square[i][k+1] ? square[i+1][k] :
                                                         square[i][k+1]);
    }
 }

  printf("Smallest 2-way path sum: %llu\n", square[0][0]);

  fclose(file);
  return 0;
}
