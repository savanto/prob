/* Distinct powers.
 * Problem 029
 *
 * Consider all integer combinations of a^b for 2 <= a <= 5 and 2 <= b <= 5:
 *
 *      2^2 = 4, 2^3 = 8, 2^4 = 16, 2^5 = 32
 *      3^2 = 9, 3^3 = 27, 3^4 = 81, 3^5 = 243
 *      4^2 = 16, 4^3 = 64, 4^4 = 256, 4^5 = 1024
 *      5^2 = 25, 5^3 = 125, 5^4 = 625, 5^5 = 3125
 *
 * If they are then placed in numerical order, with any repeats removed, we
 * get the following sequence of 15 distinct terms:
 *
 *      4, 5, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
 *
 * How many distinct terms are in the sequence generated by a^b for 
 * 2 <= a <= 100 and 2 <= b <= 100?
 */

#include <stdio.h>

#define N 100

int main() {
  // Each cell is boolean: term found?
  // Traverse all a^b, if not found mark it in term matrix and increment count.
  int terms[N+1][N+1] = { { 0 } };
  int a, b, p, q, pow, count = -1;
  for (a = 2; a <= N; ++a) {
    // Generate terms for this a
    for (b = 2; b <= N; ++b) {
      if (! terms[a][b]) {
        terms[a][b] = 1;
        ++count;
//        printf("%d^%d (%d), ", a, b, count);
      }
    }
//    printf("\n");
    // Generate terms for powers of a, but do not count them
    for (p = 2, pow = a * a; pow <= N; ++p, pow *= a) {
      for (b = 2; b <= N / p; ++b) {
        terms[pow][b] = 1;
//        printf("%d^%d (%d), %d^%d (%d), ", pow, b, count, pow, p * a, count);
      }
      for (b = 2; b <= N / p; b += a) {
          terms[pow][a*b] = 1;
      }
    }
    
//    printf("\n");
  }
  printf("Distinct terms for a^b for 2<=a,b<=%d: %d\n", N, count);
  return 0;
}
