/* Non-bouncy numbers.
 * Problem 113
 *
 * Working from left-to-right if no digit is exceeded by the digit to its
 * left it is called an increasing number; for example, 134468.
 *
 * Similarly if no digit is exceeded by the digit to its right it is called
 * a decreasing number; for example, 66420.
 *
 * We shall call a positive integer that is neither increasing nor
 * decreasing a "bouncy" number; for example, 155349.
 *
 * As n increases, the proportion of bouncy numbers below n increases such that
 * there are only 12951 numbers below one-million that are not bouncy and only
 * 277032 non-bouncy numbers below 10^10.
 *
 * How many numbers below a googol (10^100) are not bouncy?
 */

#include <stdio.h>

#define LIMIT 100000
#define STEP 10000

int main() {
  unsigned long long n, m, count, total = 0;
  int a, b, r, inc, dec;

  for (n = 1; n < LIMIT; n += STEP) {
    for (m = n, count = 0; m < n + STEP; ++m) {
      a = m % 10;
      r = m / 10;
      inc = dec = 0;
      while (r != 0) {
        b = r % 10;
        if (b < a)
          inc = 1;
        else if (b > a)
          dec = 1;
        r /= 10;
        a = b;
      }
      if (inc + dec < 2) {
        ++count;
//        printf("%llu ", m);
      }
    }
//    printf("\n");
    total += count;
    printf("%llu - %llu: %llu\n", n, n+STEP-1, count);
  }

  printf("Total below %d: %llu\n", LIMIT, total);
  return 0;
}
