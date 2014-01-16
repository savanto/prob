/* Integer right triangles.
 * Problem 039
 *
 * If p is the perimeter of a right angle triangle with integral length
 * sides, {a, b, c}, there are exactly three solutions for p = 120.
 *
 *    {20, 48, 52}, {24, 45, 51}, {30, 40, 50}
 *
 * For which value of p <= 1000, is the number of solutions maximised?
 */

#include <stdio.h>

#define MAX 1000

int main() {
  int p, t, best_p = 1, s, best_s = 0, a, b, c;
  for (p = 1; p <= MAX; ++p) {
    s = 0;
    for (a = 1; a < p; ++a) {
      for (b = a; b < p; ++b) {
        for (c = b; c < p; ++c) {
          t = a + b + c;
          if (t > p)
            break;
          else if (t == p) {
            if (a * a + b * b == c * c) {
              ++s;
              printf("p = %d {%d, %d, %d}\n", p, a, b, c);
            }
          }
        }
      }
    }
    if (s >= best_s) {
      best_s = s;
      best_p = p;
    }
  }
  printf("Most solutions (%d) for p = %d\n", best_s, best_p);
  return 0;
}
