/* Consecutive prime sum.
 * Problem 050
 *
 * The prime 41 can be written as the sum of six consecutive primes:
 *
 *    41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below
 * one-hundred.
 *
 * The longest sum of consecutive primes primes below one-thousand that adds
 * to a prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most
 * consecutive primes?
 */

#include <stdio.h>

#define N 1000000

int main() {
  // Generate primes < N using Sieve of Eratosthenes.
  unsigned int comp[N] = { 0 }, i, j, count;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  for (i = 4; i < N; i += 2)
    comp[i] = 1;
  // Sieve odds and count primes
  count = 1;
  for (i = 3; i * i < N; i += 2) {
    if (! comp[i]) {
      ++count;
      for (j = i * i; j < N; j += i)
        comp[j] = 1;
    }
  }
  // Make list of primes
  unsigned int primes[count];
  primes[0] = 2;
  for (i = 3, j = 1; i < N; i += 2)
    if (! comp[i])
      primes[j++] = i;
  // Sum up primes
  unsigned int sum = 0;
  count = 0;
  for (i = 0; sum < N; ++i) {
      sum += primes[i];
      ++count;
  }
  int k;
  i = count;
  while (i) {
    --i;
    for (j = 0; j + i < count; ++j) {
      sum = 0;
      for (k = 0; k < i; ++k)
        sum += primes[j+k];
      if (! comp[sum]) {
        printf("%d -- %d terms.\n", sum, i);
        return 0;
      }
    }
  }
  return 0;
}
