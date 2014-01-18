/* Prime permutations.
 * Problem 049
 *
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
 * increases by 3330, is unusual in two ways: (i) each of the three terms
 * are prime, and, (ii) each of the 4-digit numbers are permutations of one
 * another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
 * primes, exhibiting this property, but there is one other 4-digit
 * increasing sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in
 * this sequence?
 */

#include <stdlib.h>
#include <stdio.h>

#define N 10000

int comp[N] = { 0 };

void permutations(int p[], int P, int q[], int Q, int perms[], int* M) {
  int i;
  if (P == 0) {
    i = q[0] * 1000 + q[1] * 100 + q[2] * 10 + q[3];
    if (! comp[i])
      perms[(*M)++] = i;
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
    permutations(r, P-1, s, Q+1, perms, M);
  }
}

int combinations(int p[], int P) {
  int i, j, k, d;
  for (i = 0; i < P-2; ++i)
    for (j = i+1; j < P-1; ++j)
      for (k = j+1; k < P; ++k)
        if (p[i] < p[j] && p[j] < p[k])
          if (p[j] - p[i] == p[k] - p[j]) {
            printf("%d, %d, %d (diff = %d) [%d%d%d]\n",
                p[i], p[j], p[k], p[j] - p[i], p[i], p[j], p[k]);
            return 1;
          }
  return 0;
}

int main() {
  // Generate primes using Sieve of Eratosthenes.
  int i, j; 
  comp[0] = comp[1] = 1;  // 0, 1 not prime
  for (i = 4; i < N; i += 2)
    comp[i] = 1;
  for (i = 3; i * i < N; i += 2)
    if (! comp[i])
      for (j = i * i; j < N; j += i)
        comp[j] = 1;
  // Traverse all 4-digit primes
  int p[4], q[4], perms[24], count = 2;
  int* M = (int*) malloc(sizeof(int));
  i = 1001;
  while (count) {
    if (! comp[i]) {
      p[3] = i % 10;
      p[2] = (i % 100) / 10;
      p[1] = (i % 1000) / 100;
      p[0] = i / 1000;
      *M = 0;
      permutations(p, 4, q, 0, perms, M);
      if (combinations(perms, *M))
        --count;
    }
    i += 2;
  }
  free(M);
  return 0;
}
