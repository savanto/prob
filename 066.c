/* Diophantine equation.
 * Problem 066
 *
 * Consider quadratic Diophantine equations of the form:
 *
 *    x^2 - Dy^2 = 1
 *
 * For example, when D = 13 the minimal solution in x is 649^2 - 13 * 180^2 = 1.
 *
 * It can be assumed that there are no solutions in positive integers when D
 * is square.
 *
 * By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the
 * following:
 *
 *    3^2 - 2 * 2^2 = 1
 *    2^2 - 3 * 1^2 = 1
 *   (9)^2- 5 * 4^2 = 1
 *    5^2 - 6 * 2^2 = 1
 *    8^2 - 7 * 3^2 = 1
 *
 * Hence, by considering minimal solutions in x for D <= 7, the largest x is
 * obtained when D = 5.
 *
 * Find the value of D <= 1000 in minimal solutions of x for which the
 * largest value of x is obtained.
 */

#include <stdio.h>
#include <math.h>

#define D 1000

/************************************************************************
 * This solution works, but overflows the unsigned long long data type. *
 * Use 066.py instead.                                                  *
 ************************************************************************/
int main() {
  unsigned long long int d, x, y, max_x = 0, best_d = 0, rt, rem, num, den,
                x0, x1, y0, y1, b;
  /* Solutions to Pell's equation are found by testing each successive
   * convergent for sqrt(d). */
  for (d = 2; d <= D; ++d) {
    x = x0 = rem = rt = (unsigned long long int) sqrt((double) d);
    y = y0 = 1;
    if (rt * rt == d) /* Skip perfect squares */
      continue;
    else if (x * x - d * y * y == 1) { /* Solution found with y = 1 */
      printf("%llu^2 - %llu * %llu^2 = 1\n", x, d, y);
      if (x > max_x) {
        max_x = x;
        best_d = d;
      }
    }
    else {
      num = 1;
      den = d - rem * rem;
      b = num * (rt + rem) / den;
      rem = den * b - rem;
      num = den;
      den = d - rem * rem;
      x = x1 = b * x0 + 1;
      y = y1 = b;
      while (x * x - d * y * y != 1) {
        b = num * (rt + rem) / den;
        num = den / num;
        rem = num * b - rem;
        den = d - rem * rem;
        x = b * x1 + 1 * x0;
        y = b * y1 + 1 * y0;
        x0 = x1; y0 = y1;
        x1 = x; y1 = y;
      }
      printf("%llu^2 - %llu * %llu^2 = 1\n", x, d, y);
      if (x > max_x) {
        max_x = x;
        best_d = d;
      }
    }
  }
  printf("Largest x = %llu when D = %llu\n", max_x, best_d);
  return 0;
}
