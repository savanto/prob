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
 *    +------------+------------+
 *    |            |            |
 *    |            |     A3     |
 *    |            |            |
 * A1 |     A2     |            |
 *    |            +------+-----+
 *    |            |      | A5  |
 *    |            |  A4  +-----+
 *    |            |      | A5  |
 *    +------------+------+-----+
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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  unsigned long long week, batch, A[6] = { 0 }, i, sheets, sheet, count;
  double ev = 0;
  srand(time(NULL));

  week = 1;
  while (1) {
    // Start of week. A1 has been cut into 1 each of A2, A3, A4, A5
    //  (second A5 has been used).
    for (i = 2; i <= 5; ++i)
      A[i] = 1;
    sheets = 4;
    count = 0;
    // Batches 2-15
    for (batch = 2; batch <= 15; ++batch) {
      // Only one sheet in envelope
      if (sheets == 1)
        ++count;
      // Draw sheet
      sheet = 0;
      while (A[sheet] == 0)
        sheet = rand() % 4 + 2;
      // Sheet increases the count of all sheets > sheet,
      //  and decreases its own count.
      for (i = sheet + 1; i <= 5; ++i) {
        ++A[i];
        ++sheets;
      }
      --A[sheet];
      --sheets;
    }
    ev += count / 14.0;
    if (week % 1000000 == 0)
      printf("%.6f week %llu\n", ev / week, week);
    ++week;
  }
  return 0;
}
