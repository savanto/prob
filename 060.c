/* Prime pair sets.
 * Problem 060
 *
 * The primes 3, 7, 109, and 673, are quite remarkable. By taking any two
 * primes and concatenating them in any order the result will always be prime.
 * For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of
 * these four primes, 792, represents the lowest sum for a set of four primes
 * with this property.
 *
 * Find the lowest sum for a set of five primes for which any two primes
 * concatenate to produce another prime.
 */

#include <stdio.h>
#include "primesieve.h"

#define N 10000000
#define M 10000
#define S 20

int check(int primes[], int n, int p, unsigned char* comp) {
  int i, j;
  char s[S] = { 0 };
  int q, r;
  for (i = 0; i < n; ++i) {
    sprintf(s, "%d%d", primes[i], p);
    sscanf(s, "%d", &q);
    sprintf(s, "%d%d", p, primes[i]);
    sscanf(s, "%d", &r);
    if (q > N || r > N) {
      for (j = 3; j * j < q || j * j < r; j += 2)
        if (! comp[j])
          if (q % j == 0 || r % j == 0)
            return 0;
    }
    else if (comp[q] || comp[r])
      return 0;
  }
  return 1;
}

int main() {
  unsigned char* comp = primesieve(N);
  int bs = 5 * M;
  int a, b, c, d, e, primes[4], bp[5];
  for (a = 3; a < bs/5 && a < M; a += 2) {
    if (! comp[a]) {
      primes[0] = a;
      for (b = a + 2; a + b < 2*bs/5 && b < M; b += 2) {
        if (! comp[b] && check(primes, 1, b, comp)) {
          primes[1] = b;
          for (c = b + 2; a + b + c < 3*bs/5 && c < M; c += 2) {
            if (! comp[c] && check(primes, 2, c, comp)) {
              primes[2] = c;
              for (d = c + 2; a + b + c + d < 4*bs/5 && d < M; d += 2) {
                if (! comp[d] && check(primes, 3, d, comp)) {
                  primes[3] = d;
                  for (e = d + 2; a + b + c + d + e < bs && e < M; e += 2) {
                    if (! comp[e] && check(primes, 4, e, comp)) {
                      bp[0] = a; bp[1] = b; bp[2] = c; bp[3] = d; bp[4] = e;
                      bs = a + b + c + d + e;
                      printf("%d %d %d %d %d (sum = %d)\n", a, b, c, d, e, bs);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("Best set: ");
  int i;
  for (i = 0; i < 5; ++i)
    printf("%d ", bp[i]);
  printf("(sum = %d)\n", bs);
  free(comp);
  return 0;
}
