/* Semiprimes.
 * Problem 187
 *
 * A composite is a number containing at least two prime factors. For example,
 * 15 = 3 * 5; 9 = 3 * 3; 12 = 2 * 2 * 3.
 *
 * There are ten composites below thirty containing precisely two, not
 * necessarily distinct, prime factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
 *
 * How many composite integers, n < 10^8, have precisely two, not necessarily
 * distinct, prime factors?
 */

#include <stdlib.h>
#include <stdio.h>

#define N 100000000

int main() {
  unsigned short* comp = (unsigned short*) calloc(N, sizeof(unsigned short));
  unsigned long long n, p, count = 0;

  // Use sieve method:
  // For every integer n, if n is prime -> it has one prime factor, itself.
  // Then, for every multiple of n, add the number of prime factors that make
  //  up n. This will give each n the number of prime factors that comprise it.
  // Note: perfect squares are a special case, and require that their factor
  //  n be counted twice.
  for (n = 2; n < N; ++n) {
    if (! comp[n])
      ++comp[n];
    for (p = 2 * n; p < N; p += n)
      comp[p] += comp[n];
    if (n*n < N)
      ++comp[n*n];
  }

  // Iterate over all n; if it has two prime factors, count it.
  for (n = 2; n < N; ++n) {
    if (comp[n] == 2) {
//      printf("%d has two prime factors.\n", n);
      ++count;
    }
  }

  printf("%llu composite integers n < %llu have two prime factors.\n", 
      count, N);

  free(comp);
  return 0;
}
