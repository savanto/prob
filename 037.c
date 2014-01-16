/* Truncatable primes.
 * Problem 037
 *
 * The number 3797 has an interesting property. Being prime itself, it is
 * possible to continuously remove digits from left to right, and remain prime
 * at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
 * left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left
 * to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <stdio.h>

#define MAX 1000000
#define NUM 11

int main() {
  // Generate all primes < MAX using Sieve of Eratosthenes
  unsigned long long comp[MAX] = { 0 }, i, j, count = NUM, f, r, sum = 0;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  for (i = 4; i < MAX; i += 2)
    comp[i] = 1;  // Even numbers not prime (excluding 2)
  // Sieve single digit primes
  for (i = 3; i < 9; i += 2)
    for (j = i * i; j < MAX; j += i)
      comp[j] = 1;  // Sieve multiples of i
  // Sieve primes > 11
  // Look for truncatable primes
  printf("Truncatable primes:\n");
  i = 11;
  while (count) {
    if (! comp[i]) {
      // Check right to left
      r = i / 10;
      f = 1;
      while (! comp[r]) {
        r /= 10;
        f *= 10;
      }
      if (! r) { // this prime IS truncatable R-L
        // Check left to right
        r = i % f;
        f /= 10;
        while (! comp[r]) {
          r %= f;
          f /= 10;
        }
        if (! r) { // this prime IS truncatable L-R
          --count;
          sum += i;
          printf("%d\n", i);
        }
      }
    }
    // Do sieving
    for (j = i * i; j < MAX; j += i)
      comp[j] = 1;

    i += 2;
  }

  printf("Sum of truncatable primes = %d\n", sum);
  return 0;
}
