/* How many reversible numbers are there below one-billion?
 * Problem 145
 *
 * Some positive integers n have the property that the sum [ n + reverse(n) ]
 * consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and
 * 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 403, and
 * 904 are reversible. Leading zeros are not allowed in either n or reverse(n).
 *
 * There are 120 reversible numbers below one-thousand.
 *
 * How many reversible numbers are there below one-billion (10^9)?
 */

#include <stdio.h>

// Upper limit is 1,000,000,000
// However, no need to check numbers above 900,000,000
#define N 900000000

int main() {
  unsigned long long  n, r, k, odd, count = 0;
  for (n = 1; n < N; ++n) {
    // Reverse i digit by digit.
    r = n % 10;
    k = n / 10;
    while (k != 0) {
      r = r * 10 + k % 10;
      k /= 10;
    }

    // Skip numbers if reverse(n) < n, as we have already counted them.
    // This will also eliminate numbers with leading zeros.
    if (r < n)
      continue;

    // Check that all digits of sum are odd
    k = n + r;
    odd = 1;
    while (k != 0) {
      if ((k % 10) % 2 == 0) {
        odd = 0;
        break;
      }
      k /= 10;
    }
    if (odd) {
      count += 2;
//      printf("%llu %llu\n", n, r);
    }
  }

  printf("%llu reversible numbers below one-billion.\n", count);
  return 0;
}
