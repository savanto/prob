/* Amicable numbers.
 * Problem 021
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair
 * and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <stdio.h>

#define MAX 10000

int sum_divisors(int n) {
  int sum = 1, d, e;
  for (d = 2; d * d <= n; ++d) {
    if (n % d == 0) {
      sum += d;
      e = n / d;
      if (d != e)
        sum += e;
    }
  }
  return sum;
}

int main() {
  int n, d, e, a, amicables = 0;
  for (n = 1; n < MAX; ++n) {
    a = sum_divisors(n);
    if (a > n) {
      if (sum_divisors(a) == n)
        amicables += a + n;
    }
  }
  printf("%d\n", amicables);
  return 0;
}
