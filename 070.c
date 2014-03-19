/* Totient permutation.
 * Problem 070
 *
 * Euler's Totient function, phi(n), is used to determine the number of
 * positive numbers less than or equal to n which are relatively prime to n.
 * For example, as 1, 2, 4, 5, 7, and 8 are all less than nine and
 * relatively prime to nine, phi(9) = 6.
 * The number 1 is considered to be relatively prime to every positive
 * number, so phi(1) = 1.
 *
 * Interestingly, phi(87109) = 79180, and it can be seen that 87109 is a
 * permutation of 79180.
 *
 * Find the value of n, 1 < n < 10^7, for which phi(n) is a permutation of n
 * and the ratio of n/phi(n) produces a minimum.
 */

#include <stdlib.h>
#include <stdio.h>
#include "primesieve.h"

#define N 10000000

unsigned long long totient(unsigned long long n, unsigned char* comp,
    double minimum) {
  // If n is prime, totient = n - 1, otherwise it is computed by 
  // Euler's product formula
  // *** It is pointless to test primes, since they will not be permutaions
  // of themselves - 1
  if (! comp[n])
    return 0;//n - 1;

  // Find totient using Euler's product formula:
  // phi(n) = n * PRODUCT[p|n](1 - 1/p), 
  // where the product is over the distinct prime numbers dividing n.
  // Eg. phi(36) = phi(2^2 * 3^2) = 
  // 36 * (1 - 1/2)(1 - 1/3) = 36 * 1/2 * 2/3 = 12
  unsigned long long phi = n, pow = 0, p = n, i;

  // Produce prime factorization of n
  if (p % 2 == 0)
    phi /= 2;

  // Check if minimum has been exceeded
  if ((double) n / phi > minimum)
    return 0;

  for (i = 3; i < p; i += 2) { // odd primes
    if (! comp[i]) {
      if (p % i == 0) {
        phi = phi * (i - 1) / i;

        // Check if minimum has been exceeded
        if ((double) n / phi > minimum)
          return 0;
      }
    }
  }
  return phi;
}

int is_perm(unsigned long long n, unsigned long long phi) {
  int testn[10] = { 0 }, testphi[10] = { 0 };

  // Test whether totient is permutation of n.
  while (n != 0 && phi != 0) {
    ++testn[n%10];
    ++testphi[phi%10];
    n /= 10;
    phi /= 10;
  }
  if (n != 0 || phi != 0)
    return 0;
  int i;
  for (i = 0; i < 10; ++i)
    if (testn[i] != testphi[i])
      return 0;
  return 1;
}

int main() {
  unsigned char* comp = primesieve(N);
  unsigned long long n, p, pow, phi, i, minn, minphi;
  double minimum = N;
  unsigned char testn[10], testphi[10], fail;

  for (n = 3; n < N; n += 2) {
    phi = totient(n, comp, minimum);

    if (phi) {
      // Check whether totient is a permuation of n, and calculate ratio.
      if (is_perm(n, phi)) {
        double nphi = (double) n / phi;
        if (nphi < minimum) {
          minimum = nphi;
          minn = n;
          minphi = phi;
          printf("new minimum: phi(%llu) = %llu (%f)\n", n, phi, minimum);
        }
      }
    }
  }
  printf("phi(%llu) = %llu produces minimum n/phi(n) = %f\n",
      minn, minphi, minimum);

  free(comp);
  return 0;
}
