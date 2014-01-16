/* Digit factorials.
 * Problem 034
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of
 * their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <stdio.h>

int main() {
  // NB: 0! = 1
  const int FACTORIAL[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
  unsigned long long x = 3, n = 1, m = 9, f = 10, r, sum = 0, digit_sum;
  printf("Digit factorials:\n");
  while (n * FACTORIAL[9] > m) {
    digit_sum = FACTORIAL[x%10];
    r = x / 10;
    while (r) {
      digit_sum += FACTORIAL[r%10];
      r /= 10;
    }
    if (digit_sum == x) {
      printf("%d\n", x);
      sum += x;
    }

    ++x;
    if (x % f == 0) {
      ++n;
      m = m * 10 + 9;
      f *= 10;
    }
  }
  printf("Sum = %d\n", sum);

  return 0;
}
