/* Highly divisible triangular number
 * Problem 012
 *
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
 * The first ten terms would be:
 *      1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *      1: 1
 *      3: 1, 3
 *      6: 1, 2, 3, 6
 *     10: 1, 2, 5, 10
 *     15: 1, 3, 5, 15
 *     21: 1, 3, 7, 21
 *     28: 1, 2, 4, 7, 14, 28
 *
 * We can see that 28 is the first triangle number to have over five divisors.
 *
 * What is the value of the first triangle number to have over five hundred
 * divisors?
 */

#include <stdio.h>

int main() {
  unsigned long long i = 1, t = 0, f;
  int counter = 0;
  while (counter < 500) {
    t += i++;
    for (f = 1, counter = 0; f * f <= t; ++f)
      if (t % f == 0)
        counter += 2;
  }
  printf("%d\n", t);

  return 0;
}
