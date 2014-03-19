/* Counting summations.
 * Problem 076
 *
 * It is possible to write five as a sum in exactly six different ways:
 *
 *    4 + 1
 *    3 + 2
 *    3 + 1 + 1
 *    2 + 2 + 1
 *    2 + 1 + 1 + 1
 *    1 + 1 + 1 + 1 + 1
 *
 * How many different ways can one hundred be written as a sum of at least two
 * positive integers?
 */

#include <stdio.h>

#define TARGET 100

int main() {
  unsigned long long ways[TARGET+1] = { 1 };
  int i, sum;
  for (i = 1; i < TARGET; ++i)
    for (sum = i; sum <= TARGET; ++sum)
      ways[sum] += ways[sum-i];

  printf("Number of ways to write %d: %llu\n", TARGET, ways[TARGET]);
  return 0;
}
