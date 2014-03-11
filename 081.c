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

#include <stdlib.h>
#include <stdio.h>

#define N 80
#define F 1000000
#define INFILE "081.txt"

int main() {
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
  int i, j, k;
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

  // Convert square matrix into triangular
  unsigned long long triangle[N*2-1][N*2-1];
  for (i = 0; i < N*2-1; ++i)
    for (j = 0; j <= i; ++j)
      triangle[i][j] = (i - j >= N || j >= N ? F : square[i-j][j]);

  // Starting on penultimate row, calculate smallest path.
  for (i = N*2-3; i >= 0; --i)
    for (j = 0; j <= i; ++j)
      triangle[i][j] += triangle[i+1][j] < triangle[i+1][j+1] ?
        triangle[i+1][j] : triangle[i+1][j+1];

  printf("Smallest 2-way path sum: %llu\n", triangle[0][0]);

  fclose(file);
  return 0;
}
