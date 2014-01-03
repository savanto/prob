/* Non-abundant sums.
 * Problem 023
 *
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less
 * than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all positive integers which cannot be written as the sum of
 * two abundant numbers.
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 28124;

int sum_divisors(int n) {
  int sum = 1, d, e;
  for (d = 2; d * d <= n; ++d) {
    if (n % d == 0) {
      sum += d;
      e = n / d;
      if (d != e)
        sum += e;
    }
  }
  return sum;
}

int main() {
  int i;
  // Find all abundant numbers
  vector<int> abun;
  for (i = 12; i < MAX; ++i)
    if (sum_divisors(i) > i)
      abun.push_back(i);
  // Find all numbers that are the sum of two abundant numbers
  bool sum_abun[MAX] = { false };
  for (i = 0; i < abun.size(); ++i)
    for (int j = 0; j < abun.size(); ++j) {
      int a = abun[i] + abun[j];
      if (a < MAX)
        sum_abun[a] = true;
    }
  // Sum up the numbers not expressible as the sum of two abundant numbers
  unsigned long long sum = 0;
  for (i = 0; i < MAX; ++i)
    if (! sum_abun[i])
      sum += i;
  cout << sum << endl;
  return 0;
}
