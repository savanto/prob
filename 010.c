/* 010
 * Summation of primes
 * Problem 010
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * 
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>

#define N 2000000

int main() {
  unsigned int primes[N];
  unsigned long long i, j;
  for (i = 0; i < N; ++i)
    primes[i] = 1;
  primes[0] = primes[1] = 0;
  for (i = 2; i < N; ++i) {
    if (primes[i])
      for (j = i * i; j < N; j += i)
        primes[j] = 0;
  }

  unsigned long long sum = 0;
  for (i = 2; i < N; ++i)
    if (primes[i])
      sum += i;
  printf("%llu\n", sum);
  return 0;
}
