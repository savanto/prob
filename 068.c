/*
 * Magic 5-gon ring.
 * Problem 068
 * 
 * Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6,
 * and each line adding to nine.
 * 
 *     (4)
 *       \
 *       (3)
 *       / \
 *     (1)-(2)-(6)
 *     /
 *   (5)
 *
 * Working *clockwise*, and starting from the group of three with the numerically
 * lowest external node (4, 3, 2 in this example), each solution can be described
 * uniquely. For example, the above solution can be described by the set:
 * 4, 3, 2; 6, 2, 1; 5, 1, 3.
 * 
 * It is possible to complete the ring with four different totals: 9, 10, 11,
 * and 12. There are eight solutions in total.
 * 
 *   Total       Solution Set
 *     9       4,2,3; 5,3,1; 6,1,2
 *     9       4,3,2; 6,2,1; 5,1,3
 *     10      2,3,5; 4,5,1; 6,1,3
 *     10      2,5,3; 6,3,1; 4,1,5
 *     11      1,4,6; 3,6,2; 5,2,4
 *     11      1,6,4; 5,4,2; 3,2,6
 *     12      1,5,6; 2,6,4; 3,4,5
 *     12      1,6,5; 3,4,5; 2,4,6
 * 
 * By concatenating each group it is possible to form 9-digit strings; the
 * maximum string for a 3-gon ring is 432621513.
 * 
 * Using the numbers 1 to 10, and depending on arrangements, it is possible to
 * form 16- and 17-digit strings. What is the maximum *16-digit* string for a
 * "magic" 5-gon ring?
 * 
 *          ( )
 *            \
 *           ( )   ( )
 *          /   \  /
 *        ( )   ( )
 *        /\     /
 *     ( ) ( )-( )-( )
 *           \
 *           ( )
 */

#include <stdlib.h>
#include <stdio.h>

// We are looking for 16-digit strings
#define MAX 9999999999999999ULL
#define DIGITS 10

unsigned long long max = 0;

void check_ring(int* m, int M) {
  int sum = m[0] + m[1] + m[2], i;
  for (i = 3; i < M; i += 2)
    if (m[i] + m[i-1] + (i + 1 != M ? m[i+1] : m[1]) != sum)
      return; // sums don't match; don't do anything

  // Magic ring is satisfied (all sums match)
  // Output ring clockwise from lowest outer node.
  int min_index = (m[0] < m[3] ? 0 : 3), j;
  for (i = 5; i < M; i += 2)
    if (m[i] < m[min_index])
      min_index = i;
  i = min_index;
  unsigned long long test = 0;
  do {
    if (i == 0) {
//      printf("%d,%d,%d; ", m[i], m[i+1], m[i+2]);
      for (j = 0; j < 3; ++j) {
        test *= (m[j] == 10 ? 100 : 10);
        test += m[j];
      }
      i += 3;
    }
    else {
//      printf("%d,%d,%d; ", m[i], m[i-1], (i + 1 != M ? m[i+1] : m[1]));
      test *= (m[i] == 10 ? 100 : 10);
      test += m[i];

      test *= (m[i-1] == 10 ? 100 : 10);
      test += m[i-1];

      j = (i + 1 != M ? i+1 : 1);
      test *= (m[j] == 10 ? 100 : 10);
      test += m[j];

      i += 2;
    }
    if (i > M)
      i = 0;
  } while (i != min_index);
//  printf("\n");
  if (test < MAX && test > max)
    max = test;
}

void perms(int* n, int N, int* m, int M) {
  if (N == 0) {
    // Check if magic ring is satisfied
    check_ring(m, M);
    return;
  }

  int r[N-1], s[M+1], i, j;
  for (i = 0; i < N; ++i) {
    for (j = 0; j < i; ++j)
      r[j] = n[j];
		for (j = i + 1; j < N; ++j)
			r[j-1] = n[j];
		for (j = 0; j < M; ++j)
			s[j] = m[j];
		s[M] = n[i];
		perms(r, N - 1, s, M + 1);
  }
}

int main() {
  int n[DIGITS], m[0], i;
  for (i = 0; i < DIGITS; ++i)
    n[i] = i + 1;
  perms(n, DIGITS, m, 0);
  printf("%llu\n", max);
  return 0;
}
