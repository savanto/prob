/* Bouncy numbers.
 * Problem 112
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
 * Clearly there cannot be any bouncy numbers below one-hundred, but just
 * over half of the numbers below one-thousand (525) are bouncy. In fact,
 * the least number for which the proportion of bouncy numbers first reaches
 * 50% is 538.
 *
 * Surprisingly, bounch numbers become more and more common and by the time we
 * reach 21780 the proportion of bouncy numbers is equal to 90%.
 *
 * Find the least number for which the proportion of bouncy numbers is exaclty
 * 99%.
 */

#include <stdio.h>

#define P 99

int main() {
  unsigned long long n, count = 0;
  int a, b, r, inc, dec;
  for (n = 101; count * 100 / (n-1) != P; ++n) {
    a = n % 10;
    r = n / 10;
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

    if (inc && dec) {
      ++count;
      printf("Bouncy: %llu (%llu%%)\n", n, count * 100 / n);
    }
  }


  return 0;
}
