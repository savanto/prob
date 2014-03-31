/* Arithmetic expressions.
 * Problem 093
 *
 * By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and
 * making use of the four arithmetic operations (+, -, *, /) and brackets/
 * parentheses, it is possible to form different positive integer targets.
 *
 * For example,
 *
 *    8 = (4 * (1 + 3)) / 2
 *    14 = 4 * (3 + 1 / 2)
 *    19 = 4 * (2 + 3) - 1
 *    36 = 3 * 4 * (2 + 1)
 *
 * Note that concatenations of the digits, like 12 + 34, are not allowed.
 *
 * Using the set, {1, 2, 3, 4}, it is possible to obtain thirty-one different
 * target numbers of which 36 is the maximum, and each of the numbers 1 to 28
 * can be obtained before encountering the first non-expressible number.
 *
 * Find the set of four distinct digits, a < b < c < d, for which the longest
 * set of consecutive positive integers, 1 to n, can be obtained, giving your
 * answer as a string: abcd.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 9 * 8 * 7 * 6
#define PERMS 4 * 3 * 2 * 1
#define EPSILON 0.000001F

// Compute permutations of four elements
void permutations(int p[], int P, int q[], int Q, 
    int perms[PERMS][4], int* I) {
  int i;
  if (P == 1) {
    for (i = 0; i < Q; ++i)
      perms[(*I)][i] = q[i];
    perms[(*I)][i] = p[0];
    ++(*I);
  }
  else {
    for (i = 0; i < P; ++i) {
      int r[P-1], s[Q+1], j;
      for (j = 0; j < i; ++j)
        r[j] = p[j];
      for (j = i+1; j < P; ++j)
        r[j-1] = p[j];
      for (j = 0; j < Q; ++j)
        s[j] = q[j];
      s[Q] = p[i];
      permutations(r, P-1, s, Q+1, perms, I);
    }
  }
}

// Callback functions to perform operations
double ADD(double a, double b) { return a + b; }
double SUB(double a, double b) { return a - b; }
double MUL(double a, double b) { return a * b; }
double DIV(double a, double b) { return b != 0 ? a / b : -1000000; }

// Operator caller function.
double calc(double a, double b, double (*op)(double, double)) {
  return (*op)(a, b);
}

// Checks if a double contains an int value, and returns that int value, or 0.
int to_int(double a) {
  if (a < 0)  // This occurs if the DIV operator is called with a 0 divisor.
    return 0;
  int int_a = round(a);
  if (fabs(a - int_a) <= EPSILON)
    return int_a;
  return 0;
}

int main() {
  int a, b, c, d, i, op1, op2, op3, res, max = 0, best[4] = { 0 };
  int* I = (int*) malloc(sizeof(int));
  // Array holding pointers to the callback operators, for ease of iteration
  // over them.
  double (*ops[4])(double, double) = { ADD, SUB, MUL, DIV };
  // 1 <= a < b < c < d <= 9
  for (a = 1; a <= 6; ++a) {
    for (b = a+1; b <= 7; ++b) {
      for (c = b+1; c <= 8; ++c) {
        for (d = c+1; d <= 9; ++d) {
          int n[N] = { 0 }, p[4] = { a, b, c, d }, q[4], count = 0;
          int perms[PERMS][4];
          (*I) = 0;
          permutations(p, 4, q, 0, perms, I);
          for (i = 0; i < PERMS; ++i) {
            // For each permutation of a, b, c, d, try each arrangement of
            // parentheses and operators +, -, *, /.
            for (op1 = 0; op1 < 4; ++op1) {
              for (op2 = 0; op2 < 4; ++op2) {
                for (op3 = 0; op3 < 4; ++op3) {
                  // ((a ? b) ? (c ? d))
                  res = to_int(calc(
                                 calc(perms[i][0], perms[i][1], (*ops[op1])), 
                                 calc(perms[i][2], perms[i][3], (*ops[op3])), 
                                 (*ops[op2])));
                  n[res] = 1;

                  // (((a ? b) ? c) ? d)
                  res = to_int(calc(
                                 calc(
                                   calc(perms[i][0], perms[i][1], (*ops[op1])),
                                   perms[i][2], (*ops[op2])),
                                 perms[i][3], (*ops[op3])));
                  n[res] = 1;

                  // ((a ? (b ? c)) ? d)
                  res = to_int(calc(
                                 calc(perms[i][0], 
                                   calc(perms[i][1], perms[i][2], (*ops[op2])),
                                   (*ops[op1])),
                                 perms[i][3], (*ops[op3])));
                  n[res] = 1;

                  // (a ? ((b ? c) ? d))
                  res = to_int(calc(perms[i][0],
                                 calc(
                                   calc(perms[i][1], perms[i][2], (*ops[op2])),
                                   perms[i][3], (*ops[op3])),
                                 (*ops[op1])));
                  n[res] = 1;

                  // (a ? (b ? (c ? d)))
                  res = to_int(calc(perms[i][0],
                                 calc(perms[i][1],
                                   calc(perms[i][2], perms[i][3], (*ops[op3])),
                                   (*ops[op2])),
                                 (*ops[op1])));
                  n[res] = 1;
                }
              }
            }
          }
          // Count the number of consecutive integers generated from 1 to n.
          i = 1;
          while (n[i++] != 0)
            ++count;
          printf("%d%d%d%d: %d\n", a, b, c, d, count);
          if (count > max) {
            max = count;
            best[0] = a; best[1] = b; best[2] = c; best[3] = d;
          }
        }
      }
    }
  }

  printf("Longest set of consecutive integers is 1 to %d, produced by digits "
         "%d%d%d%d.\n", max, best[0], best[1], best[2], best[3]);
  free(I);
  return 0;
}
