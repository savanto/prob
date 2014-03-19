/* Counting fractions.
 * Problem 072
 *
 * Consider the fraction, n/d, where n and d are positive integers. If n < d
 * and HCF(n, d) = 1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d <= 8 in ascending order
 * of size, we get:
 *
 *    1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3,
 *      5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that there are 21 elements in this set.
 *
 * How many elements would be contained in the set of reduced proper fractions
 * for d <= 1,000,000?
 */

#include <stdlib.h>
#include <stdio.h>
#include "primesieve.h"

#define D 1000000

int main() {
  // It appears that the solution to the problem is given by the sum of all
  // totients of d:
  // # elements = SUM(phi(d)) for d in {2..1000000}

  // Prime sieve for use in totient calculation prime factorization.
  unsigned char* comp = primesieve(D+1);
  unsigned long long int d, p, f, phi, sum = 0;

  for (d = 2; d <= D; ++d) {
    // Totient of a prime number d = d - 1.
    if (! comp[d]) {
      sum += d - 1;
//      printf("phi(%llu) = %llu\n", d, d-1);
    }
    else {
      // Produce prime factorization of d.
      phi = p = d;
      if (d % 2 == 0) {
        phi /= 2;
        p /= 2;
      }
      for (f = 3; f <= p; f += 2)
        if (! comp[f])
          if (d % f == 0) {
            phi = phi * (f - 1) / f;
            p /= f;
          }

      sum += phi;

//      if (d % 10000 == 0)
//        printf("phi(%llu) = %llu\n", d, phi);
    }
  }

  printf("%llu reduced proper fractions for d <= %llu.\n", sum, D);

  free(comp);
  return 0;
}
