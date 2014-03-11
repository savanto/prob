/* Square digit chains.
 * Problem 092
 *
 * A number chain is created by continuously adding the square of the digits
 * in a number to form a new number until it has been seen before.
 *
 * For example,
 *
 *      44->32->13->10->1->1
 *      85->89->145->42->20->4->16->37->58->89
 *
 * Therefore any chain that arrives at 1 or 89 will become stuck in an
 * endless loop. What is most amazing is that EVERY starting number will
 * eventually arrive at 1 or 89.
 *
 * How many starting numbers below ten million will arrive at 89?
 */

#include <stdlib.h>
#include <stdio.h>

#define N 10000000

int main() {
  unsigned char* nums = (unsigned char*) calloc(N, sizeof(unsigned char));
  nums[1] = 1;
  nums[89] = 89;
  // Check numbers
  // Use nums to lookup any numbers we've seen, and see where they end.
  unsigned long long i, count1 = 0, count89 = 0, j, d, r;
  for (i = 1; i < N; ++i) {
    j = i;
    while (! nums[j]) {
      r = 0;
      while (j != 0) {
        d = j % 10;
        r += d * d;
        j /= 10;
      }
      j = r;
    }
    switch (nums[j]) {
      case 1:
        ++count1;
        nums[i] = 1;
        break;
      case 89:
        ++count89;
        nums[i] = 89;
        break;
    }
  }
  printf("Numbers arriving at 1: %d; at 89: %d\n", count1, count89);
  free(nums);
  nums = NULL;
  return 0;
}
