/* Consecutive positive divisors.
 * Problem 179
 *
 * Find the number of integers 1 < n < 10^7, for which n and n + 1 have the
 * same number of positive divisors. For example, 14 has the positive divisors
 * 1, 2, 7, 14 while 15 has 1, 3, 5, 15.
 */

#include <stdlib.h>
#include <stdio.h>

#define N 10000000

int main() {
  unsigned short* divisors = 
    (unsigned short*) calloc(N, sizeof(unsigned short));
  unsigned long long n, d, count = 0;

  // Use sieving method:
  // For each n {1..N}, add 1 to each multiple of n.
  divisors[1] = 1;
  for (n = 2; n < N; ++n) {
    ++divisors[n];
    for (d = n; d < N; d += n)
      ++divisors[d];
  }

  // Divisors array holds the number of divisors of each n.
  // Count all pairs of n and n+1 that have the same number of divisors.
  for (n = 2; n < N; ++n) {
    if (divisors[n] == divisors[n-1]) {
      ++count;
//      printf("%d and %d have %d divisors.\n", n-1, n, divisors[n]);
    }
  }

  printf("Number of integers 1 < n < %d for which sigma0(n) == sigma0(n+1): "
         "%d.\n", N, count);

  free(divisors);
  return 0;
}
