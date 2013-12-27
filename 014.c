/* Longest Collatz sequence
 * Problem 014
 *
 * The following iterative sequence is defined for the set of positive integers:
 *      n -> n/2  (n is even)
 *      n -> 3n+1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence:
 *      13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>

int main() {
  int i, max_chain = 0, chain, max_i;
  unsigned long long term;
  for (i = 1000000; i > 0; --i) {
    term = i;
    chain = 1;
    while (term != 1) {
      if (term % 2 == 0)
        term /= 2;
      else
        term = 3 * term + 1;
      ++chain;
    }
    if (chain > max_chain) {
      max_chain = chain;
      max_i = i;
    }
  }

  printf("%d: %d terms\n", max_i, max_chain);

  return 0;
}
