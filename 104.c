/* Pandigital Fibonacci ends.
 * Problem 104
 *
 * The Fibonacci sequence is defined by the recurrence relation:
 *
 *    Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
 *
 * It turns out that F541, which contains 113 digits, is the first Fibonacci
 * number for which the last nine digits are 1-9 pandigital (contain all the
 * digits 1 to 9, but not necessarily in order). And F2749, which contains 575
 * digits, is the first Fibonacci number for which the first nine digits are
 * 1-9 pandigital.
 *
 * Given that Fk is the first Fibonacci number for which the first nine digits
 * AND the last nine digits are 1-9 pandigital, find k.
 */

#include <stdio.h>
#include <math.h>

#define LOWER 1000000000
//             987654321
#define MASK   511 // 0b111111111

#define LOG_PHI 0.20898764024997873
#define LOG_SQRT_5 0.3494850021680094
int is_bipolar_pandigital(int n, int f) {
  /* Fn = int(phi^n / sqrt(5))
   * log(Fn) = log(phi^n / sqrt(5))
   *         = n * log(phi) - log(sqrt(5))
   */
  if (f < LOWER / 10)
    return 0;
  int digits = 0, d;
  while (f != 0) {
    d = f % 10;
    digits ^= (1 << (d - 1));
    f /= 10;
  }
  if (digits != MASK)
    return 0;

  double fn = n * LOG_PHI - LOG_SQRT_5;
  int whole = (int) fn;
  double frac = fn - whole;
  int u = pow(10, frac) * pow(10, (whole < 9 ? whole : 8));
  digits = 0;
  while (u != 0) {
    d = u % 10;
    digits ^= (1 << (d - 1));
    u /= 10;
  }
  if (digits != MASK)
    return 0;

  return 1;
}

int main() {

  int f1 = 1, f2 = 1, f3 = (f1 + f2) % LOWER, k = 3;

  while (! is_bipolar_pandigital(k, f3)) {
    f1 = f2;
    f2 = f3;
    f3 = (f1 + f2) % LOWER;
    ++k;
  }

  printf("F%d is pandigital at both ends.\n", k);
  return 0;
}
