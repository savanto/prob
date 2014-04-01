/* Prime cube partnership.
 * Problem 131
 *
 * There are some prime values, p, for which there exists a positive integer, n,
 * such that the expression n^3 + p*n^2 is a perfect cube.
 *
 * For example, when p = 19, 8^3 + 19 * 8^2 = 12^3.
 *
 * What is perhaps most surprising is that for each prime with this property
 * the value of n is unique, and there are only four such primes below one-
 * hundred.
 *
 * How many primes below one million have this remarkable property?
 */

#include <stdlib.h>
#include <stdio.h>
#include "primesieve.h"

#define P 1000000

int main() {
  unsigned char* comp = primesieve(P);
  unsigned long long p, n, k, m, count = 0;

  // By generating such primes under 100 by brute force, a pattern becomes
  // apparent: 
  //  n^3 + n^2 * p = m^3
  //  n = k^3 for k = {1, 2, 3, ...}
  //  m = k^3 + k^2 = n + k^2
  //  p = (m^3 - n^3) / n^2  --> reduces down to p = 3(k^2 + k) + 1
  // From here, it is sufficient to iterate over positive integers k,
  //  deriving n, m, and p, and checking p for primeness.
  // If p is prime, relationship holds, otherwise skip this k/n.
  for (k = 1, p = 3 * (k*k + k) + 1; p < P; ++k, p = 3 * (k*k + k) + 1) {
    if (! comp[p]) {
      n = k*k*k;
      m = k*k + n;
      printf("%llu^3 + %llu^2 * %llu = %llu^3\n", n, n, p, m);
      ++count;
    }
  }

  printf("%llu primes < %llu have this property.\n", count, P);
  free(comp);
  return 0;
}
