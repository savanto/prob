/* Prime power triples.
 * Problem 087
 *
 * The smallest number expressible as the sum of a prime square, prime cube,
 * and prime fourth power is 28. In fact, there are exactly four numbers
 * below fifty that can be expressed in such a way:
 *
 *    28 = 2^2 + 2^3 + 2^4
 *    33 = 3^2 + 2^3 + 2^4
 *    49 = 5^2 + 2^3 + 2^4
 *    47 = 2^2 + 3^3 + 2^4
 *
 * How many numbers below fifty million can be expressed as the sum of a
 * prime square, prime cube, and prime fourth power?
 */

#include <stdlib.h>
#include <stdio.h>
#include "primesieve.h"

#define M 50000000
// Square-root of the max, 50,000,000
#define I 7072
// Cube-root of the max
#define J 369
// Fourth-root of the max
#define K 85

int main() {
  unsigned char* comp = primesieve(I);
  unsigned char* found = (unsigned char*) calloc(M, sizeof(unsigned char));
  unsigned long long count = 0;
  int i, j, k;

  for (i = 2; i < I; ++i)
    if (! comp[i])
      for (j = 2; j < J; ++j)
        if (! comp[j])
          for (k = 2; i*i + j*j*j + k*k*k*k < M; ++k)
            if (! comp[k]) {
              if (! found[i*i + j*j*j + k*k*k*k])
                ++count;
              ++found[i*i + j*j*j + k*k*k*k];
            }

  printf("Numbers expressible as the sum of a prime square, prime cube,\n"
         "and prime fourth power below %llu: %llu\n", M, count);

  free(comp);
  return 0;
}
