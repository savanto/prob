/* Right triangles with integer coordinates.
 * Problem 091
 *
 * The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and
 * are joined to the origin, O (0, 0), to form triangle OPQ.
 *
 *    [ See figure. ]
 *
 * There are exactly fourteen triangles containing a right angle that can be
 * formed when each co-ordinate lies between 0 and 2 inclusive; that is,
 * 0 <= x1, y1, x2, y2 <= 2.
 *
 *    [ See figure. ]
 *
 * Given that 0 <= x1, y1, x2, y2 <= 50, how many right triangles can be formed?
 */

#include <stdio.h>
#include <math.h>

#define UPPER 50

int gcd(int a, int b) {
  if (b > a) {
    int temp = a;
    a = b;
    b = temp;
  }
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  int px, py, qx, qy, dyPQ, dxPQ, dyOP, dxOP, dyOQ, dxOQ, hcf, triangles = 0;
  // Brute force approach, should take no more than UPPER^4 time, ie.
  // 50^4 ~ 6M iterations
  for (py = 1; py <= UPPER; ++py) {     // P does not lie on x-axis
    for (px = 0; px <= UPPER; ++px) {
      for (qx = 1; qx <= UPPER; ++qx) { // Q does not lie on y-axis
        for (qy = 0; qy <= py; ++qy) {  // Q does not exceed P, to prevent
                                        //   double counting.
          // P == Q, skip
          if (px == qx && py == qy)
            continue;
          // P == (0, 0) or Q == (0, 0), skip
          if ((px == 0 && py == 0) || (qx == 0 && qy == 0))
            continue;

          // P on y-axis, Q on x-axis, right angle at origin
          if (px == 0 && qy == 0)
            ++triangles;
          // Q on x-axis, PQ is vertical, right angle at Q
          else if (qy == 0 && px == qx)
            ++triangles;
          // P is on y-axis, PQ is horizontal, right angle at P
          else if (px == 0 && py == qy)
            ++triangles;
          else {
            // PQ is vertical or horizontal, but no right angle is formed since
            // neither P nor Q lie on an axis. Skip.
            if (px == qx || py == qy)
              continue;

            // Calculate *reduced* slope of PQ.
            dyPQ = qy - py;
            dxPQ = qx - px;
            hcf = gcd(abs(dyPQ), abs(dxPQ));
            dyPQ /= hcf;
            dxPQ /= hcf;

            // Calculate *reduced* slope of OP
            hcf = py != 0 && px != 0 ? gcd(py, px) : 1;
            dyOP = py / hcf;
            dxOP = px / hcf;

            // Calculate reduced slope of OQ
            hcf = qy != 0 && qx != 0 ? gcd(qy, qx) : 1;
            dyOQ = qy / hcf;
            dxOQ = qx / hcf;

            // Right angle at Q if PQ perpendicular to OQ.
            // Right angle at P if PQ perpendicular to OP.
            // Two lines are perpendicular if their slopes are negative
            //  inverses of each other.
            // Check that dy/dx == -dx/dy. OP and OQ will never have negative
            //  slopes, but PQ has negative slope if one of qy-py or qx-px is
            //  negative.
            if ((abs(dyPQ) == dxOQ && abs(dxPQ) == dyOQ && dyPQ * dxPQ < 0) || 
                (abs(dyPQ) == dxOP && abs(dxPQ) == dyOP && dyPQ * dxPQ < 0))
              ++triangles;
          }
        }
      }
    }
  }

  printf("%d right triangles formed given that 0 <= x1, y1, x2, y2 <= %d.\n",
      triangles, UPPER);
  return 0;
}
