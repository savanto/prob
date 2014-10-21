/* Path sum: four ways.
 * Problem 083
 *
 * NOTE: This problem is a significantly more challenging version of
 * Problem 081.
 *
 * In the 5 by 5 matrix below, the minimal path sum from the top left to the
 * bottom right, by moving left, right, up, and down, is indicated in bold and
 * red and is equal to 2297.
 * 
 *    (131) 673 (234)(103)( 18)
 *    (201)( 96)(342) 965 (150)
 *     630  803  746 (422)(111)
 *     537  699  497 (121) 956
 *     805  732  524 ( 37)(331)
 *
 * Find the minimum path sum, in 083.txt, a 31K text file containing a
 * 80 by 80 matrix, from the top left to the bottom right by moving left, right,
 * up, and down.
 */

#include <stdio.h>
#include <limits.h>

#define N 5//80
#define INFILE "083.txt"

int main() {
  int i, j, k;

  // Test matrix from example
  int square[N][N] = { { 131, 673, 234, 103,  18 },
                       { 201,  96, 342, 965, 150 },
                       { 630, 803, 746, 422, 111 },
                       { 537, 699, 497, 121, 956 },
                       { 805, 732, 524,  37, 331 } };

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

  int visited[N][N];
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j)
      visited[i][j] = INT_MAX;

  visited[0][0] = square[0][0];
  for (i = 0; i < N; ++i) {
    for (j = 0; j < N; ++j) {





//  fclose(file);
  return 0;
}
