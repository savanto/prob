/* Spiral primes.
 * Problem 058
 *
 * Starting with 1 and spiralling anticlockwise in the following way, a
 * square spiral with side length 7 is formed.
 *
 *    (37)36 35 34 33 32(31)
 *     38(17)16 15 14(13)30
 *     39 18( 5) 4( 3)12 29
 *     40 19  6  1  2 11 28
 *     41 20( 7) 8  9 10 27
 *     42 21 22 23 24 25 26
 *    (43)44 45 46 47 48 49
 *
 * It is interesting to note that the odd squares lie along the bottom right
 * diagonal, but what is more interesting is that 8 out of the 13 numbers
 * lying along both diagonals are prime; that is, a ratio of 8/13 ~ 62%.
 *
 * If one complete new layer is wrapped around the spiral above, a square
 * spiral with side length 9 will be formed. If this process is continued,
 * what is the side length of the square spiral for which the ratio of
 * primes along both diagonals first falls below 10%?
 */

#include <stdlib.h>
#include <stdio.h>

#define N 10000000
#define R 0.1


inline int prime(unsigned int n, unsigned int* comp) {
  if (n < N)
    return ! comp[n];
  else {
    if (n % 2 == 0)
      return 0;
    int i;
    for (i = 3; i < N; i += 2)
      if (! comp[i])
        if (n % i == 0)
          return 0;
  }
  return 1;
}

int main() {
  // Generate primes < N using Sieve of Eratosthenes
  unsigned int* comp = (unsigned int*) calloc(N, sizeof(unsigned int));
  unsigned int i, j;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  for (i = 4; i < N; i += 2)
    comp[i] = 1; // Evens > 2 composite
  for (i = 3; i * i < N; i += 2)
    if (! comp[i])
      for (j = i * i; j < N; j += i)
        comp[j] = 1;  // Multiples of odds composite
  printf("Generated sieve for primes < %d.\n", N);
  // Calculate diagonals of spiral
  unsigned int count = 5, primes = 3;
  double ratio = (double) primes / count;
  i = 3;
  while (ratio > R) {
    i += 2;
    count += 4;
    // top left: (i-1)^2 + 1
    if (prime((i-1)*(i-1)+1, comp))
      ++primes;
    // top right: (i-1)^2 - (i-2)
    if (prime((i-1)*(i-1)-(i-2), comp))
      ++primes;
    // bot left: i^2 - (i-1)
    if (prime(i*i-(i-1), comp))
      ++primes;
    ratio = (double) primes / count;
  }
  printf("At %llux%llu, ratio of primes on diagonals = %llu/%llu ~ %f\n",
      i, i, primes, count, ratio);
  free(comp);
  return 0;
}
