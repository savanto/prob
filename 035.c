/* Circular primes.
 * Problem 035
 *
 * The number, 197, is called a circular prime because all rotations of the
 * digits: 197, 971, 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
 * 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include <stdio.h>

#define MAX 1000000

int main() {
  // Precalculate all primes < MAX using Sieve of Eratosthenes.
  int comp[MAX] = { 0 }, i, j, count = 0;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  // Eliminate evens
  for (i = 4; i < MAX; i += 2)
    comp[i] = 1;
  // Sieve odds
  for (i = 3; i * i < MAX; i += 2)
    for (j = i * i; j < MAX; j += i)
      comp[j] = 1;

  // Traverse primes
  printf("Circular primes:\n");
  int f = 1, p;
  for (i = 2; i < MAX; ++i) {
    if (i / f != 0)
      f *= 10;
    if (! comp[i]) {
      // Check for circularity
      p = i;
      do {
        p = (p % 10) * f/10 + p / 10;
      } while (! comp[p] && p != i);
      if (p == i) {
        printf("%d\n", i);
        ++count;
      }
    }
  }
  printf("Total number of circular primes < %d = %d\n", MAX, count);
  return 0;
}
