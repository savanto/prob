/* Totient maximum.
 * Problem 069
 *
 * Euler's Totient function, phi(n), is used to determine the number of
 * numbers less than n which are relatively prime to n. For example, as
 * 1, 2, 4, 5, 7, and 8 are all less than nine and relatively prime to nine,
 * phi(9) = 6.
 *
 * +--------------------------------------+
 * |n |Relatively Prime |phi(n) |n/phi(n) |
 * +--+-----------------+-------+---------+
 * |2 |1                |1      |2        |
 * |3 |1,2              |2      |1.5      |
 * |4 |1,3              |2      |2        |
 * |5 |1,2,3,4          |4      |1.25     |
 * |6 |1,5              |2      |3        |
 * |7 |1,2,3,4,5,6      |6      |1.1666...|
 * |8 |1,3,5,7          |4      |2        |
 * |9 |1,2,4,5,7,8      |6      |1.5      |
 * |10|1,3,7,9          |4      |2.5      |
 * +--------------------------------------+
 *
 * It can be seen that n = 6 produces a maximum n/phi(n) for n <= 10.
 *
 * Find the value of n <= 1000000 for which n/phi(n) is a maximum.
 */

#include <stdlib.h>
#include <stdio.h>
#include "primesieve.h"

#define N 1000001

// Using Euler's product formula:
// phi(n) = n * PRODUCT[p|n](1 - 1/p), where the product is over the distinct
// prime numbers dividing n.
// Eg. phi(36) = phi(2^2 * 3^2) = 36 * (1 - 1/2)(1 - 1/3) = 36 * 1/2 * 2/3 = 12
int main() {
  unsigned char* comp = primesieve(N);
  unsigned long long int n, j, k, pow, phi, maxn;
  double maxnphi = 0;
  for (n = 2; n < N; ++n) {
    if (! comp[n]) // number is prime
      phi = (n-1);
    else {
      phi = n;
      pow = 0;
      k = n;
      while (k % 2 == 0) {
        ++pow;
        k /= 2;
      }
      if (pow)
        phi /= 2;
      for (j = 3; k != 1; j += 2) {
        pow = 0;
        while (k % j == 0) {
          ++pow;
          k /= j;
        }
        if (pow)
          phi = phi * (j - 1) / j;
      }
    }
    double nphi = (double) n / phi;
    if (nphi > maxnphi) {
      maxnphi = nphi;
      maxn = n;
    }
  }

  printf("Maximum n / phi(n) = %.4f for n = %d\n", maxnphi, maxn);

  free(comp);
  comp = NULL;
  return 0;
}
