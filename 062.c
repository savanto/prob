/* Cubic permutations.
 * Problem 062
 *
 * The cube 41063625 (345^3), can be permuted to produce two other cubes:
 * 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest
 * cube which has exactly three permutations of its digits which are also
 * cubes.
 *
 * Find the smallest cube for which exactly five permutations of its digits
 * are cubes.
 */

#include <stdio.h>

#define N 5
#define CUBES 10000

inline int check(int digits[], int pdigits[]) {
  int i;
  for (i = 0; i < 10; ++i)
    if (digits[i] != pdigits[i])
      return 0;
  return 1;
}

int main() {
  /* Precalculate some cubes */
  unsigned long long int cubes[CUBES], r;
  unsigned long long int i, j, f = 10;
  for (i = 0; i < CUBES; ++i)
    cubes[i] = i * i * i;
  /* Look for cubes with permutations */
  for (i = 0; i < CUBES; ++i) {
    while (i > f)
      f *= 10;
    int digits[10] = { 0 }, results[N] = { i }, n = 1;
    r = cubes[i];
    while (r != 0) {
      ++digits[r%10];
      r /= 10;
    }
    for (j = i + 1; j < f; ++j) {
      int pdigits[10] = { 0 };
      r = cubes[j];
      while (r != 0) {
        ++pdigits[r%10];
        r /= 10;
      }
      if (check(digits, pdigits))
        results[n++] = j;
      if (n == N) {
        for (i = 0; i < N; ++i)
          printf("%d^3 = %llu\n", results[i], cubes[results[i]]);
        return 0;
      }
    }
  }
  printf("asdf\n");

  return 0;
}
