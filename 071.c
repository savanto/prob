/* Ordered fractions.
 * Problem 071
 *
 * Consider the fraction, n/d, where n and d are positive integers. If n < d
 * and HCF(n, d) = 1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d <= 8 in ascending order
 * of size, we get:
 *
 *    1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3,
 *      5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that 2/5 is the fraction immediately to the left of 3/7.
 *
 * By listing the set of reduced proper fractions for d <= 1,000,000 in
 * ascending order of size, find the numerator of the fraction immediately to
 * the left of 3/7.
 */

#include <stdio.h>

#define D 1000000

int main() {
  unsigned long long n, d, left_n = 0, left_d = 1;
  for (d = 2; d <= D; ++d) {

    n = 3 * d / 7;
    if (n % 3 != 0 && d % 7 != 0 && n * left_d > left_n * d) {
      left_n = n;
      left_d = d;
    }
  }

  printf("Fraction to the left of 3/7: %llu/%llu\n", left_n, left_d);
  return 0;
}
