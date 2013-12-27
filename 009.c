/* Special Pythagorean triplet
 * Problem 009
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which, a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>

int main() {
  int a, b, c;
  for (a = 1; a < 333; ++a) {
    for (b = a + 1; b < 500; ++b) {
      for (c = b + 1; c < 998; ++c) {
        if (a * a + b * b == c * c && a + b + c == 1000) {
          printf("%d %d %d\n", a, b, c);
          printf("%d\n", a * b * c);
          return 0;
        }
      }
    }
  }
  return 1;
}
