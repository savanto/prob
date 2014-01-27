/* Powerful digit counts
 * Problem 063
 *
 * The 5-digit number, 16807 = 7^5, is also a fifth power. Similarly, the
 * 9-digit number, 134217728 = 8^9, is a ninth power.
 *
 * How many n-digit positive integers exist which are also an nth-power?
 */

#include <stdio.h>

#define I 20 // Max power to prevent overflow

inline unsigned long long power(unsigned long long base, int pow) {
  int i;
  unsigned long long res = 1;
  for (i = 0; i < pow; ++i)
    res *= base;
  return res;
}

int main() {
  // Count 9^20 and 9^21 manually, since they overflow.
  unsigned long long count = 2, f = 1;
  int n, i;
  for (i = 1; i <= I; ++i) {
    n = 1;
    while (power(n, i) < f)
      ++n;
    while (power(n, i) < f * 10) {
      ++count;
      printf("%d-digit: %d^%d = %llu\n", i, n, i, power(n, i));
      ++n;
    }
    f *= 10;
  }
  printf("20-digit: 9^20 = 12157665459056928801\n");
  printf("21-digit: 9^21 = 109418989131512359209\n");

  printf("%llu n-digit pos ints are also an nth power.\n", count);
  return 0;
}
