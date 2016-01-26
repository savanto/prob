/* Paper sheets of standard sizes: an expected-value problem.
 * Problem 151
 *
 * A printing shop runs 16 batches (jobs) every week and each batch requires a
 * sheet of special colour-proofing paper of size A5.
 *
 * Every Monday morning, the foreman opens a new envelope, containing a large
 * sheet of the special paper with size A1.
 *
 * He proceeds to cut it in half, thus getting two sheets of size A2. Then he
 * cuts one of them in half to get two sheets of size A3 and so on until he
 * obtains the A5-size sheet needed for the first batch of the week.
 *
 * All the unused sheets are placed back in the envelope.
 *
 *    +------------+-------------+
 *    |            |             |
 *    |            |      A3     |
 *    |            |             |
 * A1 |     A2     +------+------+
 *    |            |      |  A5  |
 *    |            |  A4  +------+
 *    |            |      |  A5  |
 *    +------------+------+------+
 *
 * At the beginning of each subsequent batch, he takes from the envelope one
 * sheet of paper at random. If it is of size A5, he uses it. If it is larger,
 * he repeats the 'cut-in-half' procedure until he has what he needs and any
 * remaining sheets are always placed back in the envelope.
 *
 * Excluding the first and last batch of the week, find the expected number of
 * times (during each week) that the foreman finds a single sheet of paper in
 * the envelope.
 *
 * Give your answer rounded to six decimal places using the format x.xxxxxx .
 */

#include <stdio.h>

double cut(int a2, int a3, int a4, int a5) {
  int sheets = a2 + a3 + a4 + a5;
  double count = 0;
  if (sheets == 0)
    return 0;
  if (sheets == 1 && a5 == 0)
    count = 1;
  if (a2)
    count += a2 * cut(a2-1, a3+1, a4+1, a5+1);
  if (a3)
    count += a3 * cut(a2, a3-1, a4+1, a5+1);
  if (a4)
    count += a4 * cut(a2, a3, a4-1, a5+1);
  if (a5)
    count += a5 * cut(a2, a3, a4, a5-1);
  return count / sheets;
}

int main() {
  printf("%f\n", cut(1, 1, 1, 1));
  return 0;
}

