/* Prime summations.
 * Problem 077
 *
 * It is possible to write ten as the sum of primes in exactly five different
 * ways:
 *
 *    7 + 3
 *    5 + 5
 *    5 + 3 + 2
 *    3 + 3 + 2 + 2
 *    2 + 2 + 2 + 2 + 2
 *
 * What is the first value which can be written as the sum of primes in over
 * five thousand different ways?
 */

#include <stdlib.h>
#include <stdio.h>
#include "primesieve.h"

#define LIMIT 1000000
#define TARGET 5000

int main() {
  unsigned char* comp = primesieve(LIMIT+1);
  unsigned long long* ways = 
    (unsigned long long*) calloc(LIMIT+1, sizeof(unsigned long long));
  int prime, sum, value = 2;

  // Try each value until the TARGET is reached
  for (value = 2; ways[value-1] <= TARGET; ++value) {
    // Reset ways array
    for (ways[0] = 1, sum = 1; sum <= value; sum++)
      ways[sum] = 0;

    // Count ways using dynamic programming technique.
    // Special case: prime = 2
    for (sum = prime = 2; sum <= value; ++sum)
      ways[sum] += ways[sum-prime];
    // Odd primes
    for (prime = 3; prime <= value; prime += 2)
      if (! comp[prime])
        for (sum = prime; sum <= value; ++sum)
          ways[sum] += ways[sum-prime];

    printf("%d: %llu ways\n", value, ways[value]);
  }

  printf("The first value which can be written as the sum of primes in over\n"
         "%d different ways is: %d.\n", TARGET, value-1);

  free(comp);
  free(ways);
  return 0;
}
