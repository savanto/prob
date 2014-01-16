/* Coin sums.
 * Problem 031
 *
 * In England the currency is made up of pound, L, and pence, p, and there
 * are eight coins in general circulation:
 *
 *        1p, 2p, 5p, 10p, 20p, 50p, L1 (100p) and L2 (200p).
 *
 * It is possible to make L2 in the following way:
 *
 *        1xL1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
 *
 * How many different ways can L2 be made using any number of coins?
 */

#include <stdio.h>

#define TARGET 200
#define NUM_COINS 8

int main() {
  const int COINS[NUM_COINS] = { 1, 2, 5, 10, 20, 50, 100, 200 };
  unsigned long long ways[TARGET+1] = { 1 };
  int coin, value;
//  for (value = 0; value <= TARGET; ++value)
//    printf("%d\n", ways[value]);
  for (coin = 0; coin < NUM_COINS; ++coin)
    for (value = COINS[coin]; value <= TARGET; ++value)
      ways[value] += ways[value-COINS[coin]];
  printf("Number of ways to make %dp: %d\n", TARGET, ways[TARGET]);

  return 0;
}
