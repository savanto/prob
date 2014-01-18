/* Pandigital prime.
 * Problem 041
 *
 * We shall say that an n-digit number is pandigital if it makes use of all
 * the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital
 * and is also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */

#include <stdlib.h>
#include <stdio.h>

// n < 8, since numbers composed of 1-8 or 1-9 are divisible by 3, and
// therefore not eligible for primeness.
#define MAX 7654321

int pandigital(unsigned int i) {
  if (i % 10 == 0)
    return 0;
  unsigned int check = 1 << (i % 10 - 1), mask = 1, f = 1, r = i / 10;
  while (r) {
    if (r % 10 != 0)
      check ^= 1 << (r % 10 - 1);
    mask |= 1 << f++;
    r /= 10;
  }
  return check == mask;
}

int main() {
  // Generate primes <= MAX using Sieve of Eratosthenes
  unsigned int *comp = (unsigned int *) calloc(MAX+1, sizeof(unsigned int));
  unsigned int i, j;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  // Initialize, with evens > 2 not prime.
  for (i = 4; i <= MAX; i += 2)
    comp[i] = 1;
  // Sieve out odd numbers
  for (i = 3; i * i <= MAX; i += 2)
    for (j = i * i; j <= MAX; j += i)
      comp[j] = 1;
  // Traverse primes largest to smallest and check if they are pandigital
  i = MAX;
  while (comp[i] || ! pandigital(i))
    i -= 2;
  printf("Largest pandigital prime = %d\n", i);
  return 0;
}
