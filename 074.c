/* Digital factorial chains.
 * Problem 074
 *
 * The number 145 is well known for the property that the sum of the factorial
 * of its digits is equal to 145:
 * 
 *    1! + 4! + 5! = 1 + 24 + 120 = 145
 * 
 * Perhaps less well known is 169, in that it produces the longest chain of
 * numbers that link back to 169; it turns out that there are only three such
 * loops that exist:
 * 
 *    169 -> 363601 -> 1454 -> 169
 *    871 -> 45361 -> 871
 *    872 -> 45362 -> 872
 * 
 * It is not difficult to prove that EVERY starting number will eventually get
 * stuck in a loop. For example,
 * 
 *    69 -> 363600 -> 1454 -> 169 -> 363601 ( -> 1454)
 *    78 -> 45360 -> 871 -> 45361 ( -> 871)
 *    540 -> 145 ( -> 145)
 * 
 * Starting with 69 produces a chain of five non-repeating terms, but the
 * longest non-repeating chain with a starting number below one million is
 * sixty terms.
 * 
 * How many chains, with a starting number below one million, contain exactly
 * sixty non-repeating terms?
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#define N 1000000

int factorial(int n) {
  int f = 1;
  for (; n != 0; --n)
    f *= n;
  return f;
}

int main() {
  int* chains = (int*) calloc(3 * N, sizeof(int));
  int inter[60];
  int i, j, r, rep, c, count = 0;
  for (i = 0; i < N; ++i) {
    j = i;
    c = 0;
    rep = 0;
//    printf("%d", i);
    while (chains[j] == 0 && ! rep) {
      inter[c++] = j;
      r = j;
      j = 0;
      while (r != 0) {
        j += factorial(r % 10);
        r /= 10;
      }
      for (r = 0; r < c; ++r)
        if (inter[r] == j) {
          rep = 1;
          break;
        }
//      if (! rep)
//        printf(" -> %d", j);
    }
    // Update intermediate chain values too
    for (r = 0; r < c; ++r)
      chains[inter[r]] = c + chains[j] - r;
    // Update base chain value
    chains[i] = c + chains[j];

    if (chains[i] == 60)
      ++count;

//    printf(" (%d)\n", c);
  }

  printf("Number of chains with 60 non-repeating terms: %d\n", count);

  free(chains);
  return 0;
}
