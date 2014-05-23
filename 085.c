/* Counting rectangles.
 * Problem 085
 *
 * By counting carefully it can be seen that a rectangular grid measuring
 * 3 by 2 contains eighteen rectangles:
 *
 *  +--+..+..+      +--+--+..+      +--+--+--+
 *  |  |  .  .      |  |  |  .      |  |  |  |
 *  +--+..+..+      +--+--+..+      +--+--+--+
 *  .  .  .  .      .  .  .  .      .  .  .  .
 *  +..+..+..+      +..+..+..+      +..+..+..+
 *      6               4               2
 *
 *  +--+..+..+      +--+--+..+      +--+--+--+
 *  |  |  .  .      |  |  |  .      |  |  |  |
 *  +--+..+..+      +--+--+..+      +--+--+--+
 *  |  |  .  .      |  |  |  .      |  |  |  |
 *  +--+..+..+      +--+--+..+      +--+--+--+
 *      3               2               1
 *
 * Although there exists no rectangular grid that contains exactly two million
 * rectangles, find the area of the grid with the nearest solution.
 */

#include <stdio.h>
#include <math.h>

#define TARGET 2000000

int main() {
  /* Info on solution here:
   * http://www.gottfriedville.net/mathprob/comb-subrect.html
   *
   * For n x m grid, num rectangles = [m(m+1) * n(n+1)] / 4
   */
  int diff, min_diff = TARGET, area = 0, n, m;
  for (n = 1; n < 1000; ++n) {
    for (m = 1; m < 1000; ++m) {
      diff = abs(TARGET - m * (m + 1) * n * (n + 1) / 4);
      if (diff < min_diff) {
        min_diff = diff;
        area = m * n;
      }
    }
  }
  printf("Grid with area %d produces %d rectangles.\n",
      area, TARGET - min_diff);
  return 0;
}
