/* Large non-Mersenne prime
 * Problem 097
 *
 * The first known prime found to exceed one million digits was discovered
 * in 1999, and is a Mersenne prime of the form 2^6972593 - 1; it contains
 * exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form
 * 2^p - 1, have been found which contain more digits.
 *
 * However, in 2004 there was found a massive non-Mersenne prime which
 * contains 2,357,207 digits: 28433 * 2^7830457 + 1.
 *
 * Find the last ten digits of this prime number.
 */

#include <stdio.h>

#define D 10000000000
#define P 7830457
#define K 28433

int main() {
  unsigned long long r = 1, i;
  for (i = 0; i < P; ++i)
    r = r * 2 % D;
  r = r * K % D;
  printf("Last 10 digits of %d * 2^%d + 1 = %llu\n", K, P, r + 1);
  return 0;
}
