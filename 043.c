/* Sub-string divisibility
 * Problem 043
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made
 * up of each of the digits 0 to 9 in some order, but it also has a rather
 * interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
 * note the following:
 *
 *  - d2d3d4 = 406 is divisible by 2
 *  - d3d4d5 = 063 is divisible by 3
 *  - d4d5d6 = 635 is divisible by 5
 *  - d5d6d7 = 357 is divisible by 7
 *  - d6d7d8 = 572 is divisible by 11
 *  - d7d8d9 = 728 is divisible by 13
 *  - d8d9d10 = 289 is divisible by 17
 *
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <stdio.h>

#define SIZE 10

unsigned long long int sum = 0;
const unsigned int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17 };

void divisible(int q[]) {
  int d;
  for (d = 2; d <= SIZE - 2; ++d)
    if ((q[d-1] * 100 + q[d] * 10 + q[d+1]) % PRIMES[d-2])
      return;
  // All divisibility tests pass, add it to sum
  unsigned long long int f = 1000000000;
  for (d = 0; d < SIZE; ++d) {
    sum += q[d] * f;
    f /= 10;
  }
}

void perms(int p[], int P, int q[], int Q) {
  int i;
  if (P == 0) {
    // Check for special divisibility property
    divisible(q);
    return;
  }
  int r[P-1], s[Q+1], j;
  for (i = 0; i < P; ++i) {
    for (j = 0; j < i; ++j)
      r[j] = p[j];
    for (j = i + 1; j < P; ++j)
      r[j-1] = p[j];
    for (j = 0; j < Q; ++j)
      s[j] = q[j];
    s[Q] = p[i];
    perms(r, P-1, s, Q+1);
  }
}

int main() {
  int p[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, q[SIZE], P = SIZE, Q = 0;
  perms(p, P, q, Q);

  printf("%llu\n", sum);
  return 0;
}
