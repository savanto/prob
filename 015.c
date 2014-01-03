/* Lattice paths
 * Problem 015
 *
 * Starting in the top left corner of a 2x2 grid, and only being able to move
 * to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 *      .--->--->     .--->   .     .--->   .
 *              |         |             |
 *      .   .   v     .   v--->     .   v   .
 *              |             |         |
 *      .   .   v     .   .   v     .   v--->
 *
 *
 *      .   .   .     .   .   .     .   .   .
 *      |             |             |
 *      v--->--->     v--->   .     v   .   .
 *              |         |         |
 *      .   .   v     .   v--->     v--->--->
 *
 * How many such route are there through a 20x20 grid?
 */

#include <stdio.h>

int main(int argc, char * argv[]) {
  if (argc != 2) {
    printf("Usage: 015 N (where N is the grid dimension.\n");
    return 1;
  }
  const int N = atoi(argv[1]) + 1;
  unsigned long long int arr[N];
  int i, j;
  arr[0] = 1;
  for (i = 1; i < N; ++i)
    arr[i] = 0;

  for (i = 2; i <= 2 * N - 1; ++i) {

    if (i % 2 != 0) {
      for (j = (i+1)/2-2; j > 0; --j)
        arr[j] += arr[j-1];
      arr[0] *= 2;
    }
    else {
      for (j = 0; j < i / 2; ++j)
        arr[j] += arr[j+1];
    }
    if (i > N)
      arr[(i+1)/2-1] = 0;
    else
      arr[(i+1)/2-1] = 1;
  }
  printf("%llu\n", arr[0]);
  return 0;
}

/* Solution is solved by calculating a triangle with each row representing
 * the number of paths to a given vertex of the grid. Ie.
 *                          0
 *                        1   1
 *                      1   2   1
 *                    0   3   3   0
 *                  0   3   6   3   0
 *                  .................
 * This is for a 2x2 grid (as in the example), or 3x3 nodes (n).
 * The solution is the nth coefficient of the 2*n-1 th row.
 * I use an array to hold each row (except I only hold half of the row, since
 * each row is symmetrical). Row values are computed, and the final answer
 * output as the first value in my half-row array (equivalent to the nth
 * coefficient of the final row.)
 */
