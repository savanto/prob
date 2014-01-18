/* Permuted multiples.
 * Problem 052
 *
 * It can be seen that the number 125874, and its double, 251748, contain
 * exactly the same digits, but in a different order.
 *
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
 * contain the same digits.
 */

#include <stdio.h>

int check(unsigned long long x) {
  unsigned long long mask, check, r, y;
  int i;
  mask = 1 << (x % 10 - 1);
  r = x / 10;
  while (r) {
    mask |= 1 << (r % 10 - 1);
    r /= 10;
  }
  for (i = 2; i <= 6; ++i) {
    y = i * x;
    check = 1 << (y % 10 - 1);
    r = y / 10;
    while (r) {
      check |= 1 << (r % 10 - 1);
      r /= 10;
    }
    if (check != mask)
      return 0;
  }
  return 1;
}

int main() {
  unsigned long long x = 1;
  while (! check(x))
    ++x;
  int i;
  for (i = 1; i <= 6; ++i)
    printf("%llu ", x * i);
  printf("\n");
  return 0;
}
