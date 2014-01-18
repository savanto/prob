/* Self powers.
 * Problem 048
 *
 * The series 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 *
 * Find the last ten digits of the series 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <stdio.h>

#define N 1000
#define K 10000000000LLU

int main() {
  unsigned long long int i, j, sum = 0, prod;
  for (i = 1; i <= N; ++i) {
    prod = 1;
    for (j = 0; j < i; ++j)
      prod = (prod * i) % K;
    sum += prod;
  }
  printf("1^1 + 2^2 + 3^3 + ... + %d^%d = %llu (mod %llu)\n",
      N, N, sum % K, K);
  return 0;
}
