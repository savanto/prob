/* Goldbach's other conjecture.
 * Problem 046
 *
 * It was proposed by Christian Goldbach that every odd composite number can
 * be written as the sum of a prime and twice a square.
 *
 *  9 = 7 + 2 * 1^2
 *  15 = 7 + 2 * 2^2
 *  21 = 3 + 2 * 3^2
 *  25 = 7 + 2 * 3^2
 *  27 = 19 + 2 * 2^2
 *  33 = 31 + 2 * 1^2
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of
 * a prime and twice a square?
 */

#include <stdio.h>

#define N 1000000

int main() {
  // Generate Sieve of Eratosthenes
  unsigned int comp[N] = { 0 }, i, j, s, g;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  // Mark evens > 2 as composite
  for (i = 4; i < N; i += 2)
    comp[i] = 1;
  // Sieve out odd composites
  for (i = 3; i * i < N; i += 2)
    for (j = i * i; j < N; j += i)
      comp[j] = 1;
  // Examine odd composites for Goldbach's property
  // For each one, check primes less than itself and 2 * squares.
  // NB: no need to check prime number 2, since that would not make an odd.
  for (i = 9; i < N; i += 2) {
    if (comp[i]) {
      for (j = i - 2; j != 1; j -= 2) {
        if (! comp[j]) {
          for (s = 1, g = 0; g < i; ++s)
            g = j + 2 * s * s;
          if (g == i)
            break;  // next i
        }
      }
      if (j == 1) {
        // Conjecture doesn't hold for this i
        printf("%d\n", i);
        return 0;
      }
    }
  }

  return 0;
}
