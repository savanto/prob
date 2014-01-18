/* Distinct primes factors.
 * Problem 047
 *
 * The first two consecutive numbers to have two distinct prime factors are:
 *
 *    14 = 2 * 7
 *    15 = 3 * 5
 *
 * The first three consecutive numbers to have three distinct prime factors
 * are:
 *
 *    644 = 2^2 * 7 * 23
 *    645 = 3 * 5 * 43
 *    646 = 2 * 17 * 19
 *
 * Find the first four consecutive integers to have four distinct prime
 * factors. What is the first of these numbers?
 */

#include <stdio.h>

#define N 1000
#define F 4

inline int check(int pf[]) {
  int i;
  for (i = 0; i < F; ++i)
    if (pf[i] < F)
      return 0;
  return 1;
}

int main() {
  // Generate primes < N by Sieve of Eratosthenes
  unsigned int comp[N] = { 0 }, i, j;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  // Evens > 2 are composite
  for (i = 4; i < N; i += 2)
    comp[i] = 1;
  // Sieve out odd composites
  for (i = 3; i * i < N; i += 2)
    if (! comp[i])
      for (j = i * i; j < N; j += i)
        comp[j] = 1;
  // Search for 4 consecutive ints with four distinct primes each
  int p = 0, pf[F] = { 0 };
  while (! check(pf)) {
    ++p;
    // Check whether 2 is a factor
    for (j = 0; j < F; ++j)
      pf[j] = (p + j) % 2 == 0;
    // Check whether other primes are factors
    for (i = 3; i < N; i += 2)
      if (! comp[i])
        for (j = 0; j < F; ++j)
          pf[j] += (p + j) % i == 0;
  }
  for (i = 0; i < F; ++i)
    printf("%d ", p + i);
  printf("\n");
  return 0;
}
