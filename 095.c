/* Amicable chains.
 * Problem 095
 *
 * The proper divisors of a number are all the divisors excluding the number
 * itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As
 * the sum of these divisors is equal to 28, we call it a perfect number.
 *
 * Interestingly the sum of the proper divisors of 220 is 284 and the sum of
 * the proper divisors of 284 is 220, forming a chain of two numbers. For this
 * reason, 220 and 284 are called an amicable pair.
 *
 * Perhaps less well known are longer chains. For example, starting with 12496,
 * we form a chain of five numbers:
 *
 *    12496 -> 14288 -> 15472 -> 14536 -> 14264 ( -> 12496 -> ...)
 *
 * Since this chain returns to its starting point, it is called an amicable
 * chain.
 *
 * Find the smallest member of the longest amicable chain with no element
 * exceeding one million.
 */

#include <stdio.h>

#define N 1000001

int main() {
  int sum, i, n, d[N], len, max_len = 0, min, cur;
  for (n = 1; n < N; ++n) {
    sum = 1;
    for (i = 2; i * i < n; ++ i)
      if (n % i == 0)
        sum += i + n / i;
    d[n] = i * i == n ? sum + i : sum;
  }

  for (n = 1; n < N; ++n) {
    if (! d[n])
      continue;
    cur = d[n];
    len = 1;
    int seen[N] = { 0 };
    seen[n] = 1;
    while (cur < N && ! seen[cur]) {
      ++len;
      seen[cur] = 1;
      cur = d[cur];
    }
    if (cur == n && len > max_len) {
      max_len = len;
      min = n;
      printf("%d: %d elements long\n", min, max_len);
    }
  }

  printf("Amicable chain %d elements long starts from %d\n", max_len, min);
  return 0;
}
