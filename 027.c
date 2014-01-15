/* Quadratic primes
 * Problem 027
 * Euler discovered the remarkable quadratic formula:
 *                n^2 + n + 41
 * 
 * It turns out that the formula will produce 40 primes for the consecutive
 * values n = 0 to 39.
 * However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by
 * 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
 *
 * The incredible formula n^2 - 79n + 1601 was discovered, which produces
 * 80 primes for the consecutive values n = 0 to 79. The product of the
 * coefficients, -79 and 1601, is -126479.
 *
 * Considering the quadratics of the form:
 *        n^2 + an + b, where |a| < 1000 and |b| < 1000
 *
 *        where |n| is the modulus/absolute value of n
 *        e.g. |11| = 11 and |-4| = 4
 *
 * Find the product of the coefficients, a and b, for the quadratic
 * expression that produces the maximum number of primes for consecutive
 * values of n, starting with n = 0.
 */

#include <stdio.h>
#include <math.h>

#define N 1000000

int main() {
  // Need to check primality. Generate all primes < N using Sieve of
  // Eratosthenes.
  int comp[N] = { 0 }, a, b, n, best_a, best_b, primes, most_primes = 0;
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  for (a = 2; a * a < N; ++a)
    if (! comp[a])
      for (b = 2; a * b < N; ++b)
        comp[a*b] = 1;
//  for (a = 0; a < 1001; ++a)
//    printf("%d: %d\n", a, comp[a]);

  // Try equations n^2 + an + b
  // for 0 <= n <= ?, -1000 < a, b < 1000
  for (a = -999; a < 1000; ++a) {
    for (b = -999; b < 1000; ++b) {
      // Skip composite b, since they will not produce a prime when n = 0
      if (comp[abs(b)])
        continue;
      n = 0;
      primes = 0;
      while (! comp[abs(n*n + a*n + b)]) {
        ++n;
        ++primes;
      }
      if (primes > most_primes) {
        most_primes = primes;
        best_a = a;
        best_b = b;
      }
    }
  }

  printf("Best expression: n^2 + (%d)n + (%d) with %d primes.\n",
      best_a, best_b, most_primes);
  printf("a * b = %d\n", best_a * best_b);

  return 0;
}
