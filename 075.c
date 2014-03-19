/* Singular integer right triangles.
 * Problem 075
 *
 * It turns out that 12 cm is the smallest length of wire that can be bent to
 * form an integer sided right angle triangle in exactly one way, but there are
 * many more examples.
 *
 *    12 cm: (3, 4, 5)
 *    24 cm: (6, 8, 10)
 *    30 cm: (5, 12, 13)
 *    36 cm: (9, 12, 15)
 *    40 cm: (8, 15, 17)
 *    48 cm: (12, 16, 20)
 *
 * In contrast, some lengths of wire, like 20 cm, cannot be bent to form an
 * integer sided right angle triangle, and other lengths allow more than one
 * solution to be found; for example, using 120 cm it is possible to form
 * exactly three different integer sided right angle triangles.
 *
 *    120 cm: (30, 40, 50), (20, 48, 52), (24, 45, 51)
 *
 * Given that L is the length of the wire, for how many values of
 * L <= 1,500,000 can exactly one integer sided right angle triangle be formed?
 */

#include <stdlib.h>
#include <stdio.h>

#define L 1500000

int gcd(int m, int n) {
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

int main() {
  int* triangles = (int*) calloc(L+1, sizeof(int));

  // Generate Pythagorean triplets using Euclid's formula.
  // a = m^2 - n^2, b = 2mn, c = m^2 + n^2
  // where m and n are coprime, m - n is odd, and m > n.
  int n = 1, m = 2, a = m*m - n*n, b = 2*m*n, c = m*m + n*n, l = a+b+c, k;
  for (; l <= L; ++n, m = n+1, a = m*m-n*n, b = 2*m*n, c = m*m+n*n, l = a+b+c)
    for (; l <= L; m += 2, a = m*m-n*n, b = 2*m*n, c = m*m+n*n, l = a+b+c)
      if (gcd(m, n) == 1)
        for (k = 1; k*l <= L; ++k)
          ++triangles[k*l];

  // Count up the triangles formed by a single unique Pythagorean triple.
  for (n = 0, m = 0; n <= L; ++n)
    if (triangles[n] == 1)
      ++m;

  printf("Exactly one integer sided right triangle can be formed with %d\n"
         "lengths of wire for L <= %d.\n", m, L);

  free(triangles);
  return 0;
}
