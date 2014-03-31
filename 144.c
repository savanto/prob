/* Investigating multiple reflections of a laser beam.
 * Problem 144
 *
 * In laser physics, a "white cell" is a mirror system that acts as a delay
 * line for the laser beam. The beam enters the cell, bounces around on the
 * mirrors, and eventually works its way back out.
 *
 * The specific white cell we will be considering is an ellipse with the
 * equation 4x^2 + y^2 = 100.
 *
 * The section corresponding to -0.01 <= x <= +0.01 at the top is missing,
 * allowing the light to enter and exit through the hole.
 *
 *    [ See figure. ]
 *
 * The light beam in this problem starts at the point (0.0, 10.1) just outside
 * the white cell, and the beam first impacts the mirror at (1.4, -9.6).
 *
 * Each time the laser beam hits the surface of the ellipse, it follows the
 * usual law of reflection "angle of incidence equals angle of reflection."
 * That is, both the incident and reflected beams make the same angle with the
 * normal line at the point of incidence.
 *
 * In the figure on the left, the red line shows the first two points of
 * contact between the laser beam and the wall of the white cell; the blue line
 * shows the line tangent to the ellipse at the point of incidence of the first
 * bounce.
 *
 * The slope m of the tangent line at any point (x, y) of the given ellipse is:
 * m = -4x/y.
 *
 * The normal line is perpendicular to this tangent line at the point of
 * incidence.
 *
 * The animation on the right shows the first 10 reflections of the beam.
 *
 *    [ See figure. ]
 *
 * How many times does the beam hit the internal surface of the white cell
 * before exiting?
 */

#include <stdio.h>
#include <math.h>

#define EPS 0.000001

int main() {
  // First point is the given start of beam.
  double prev_x     = 0,   prev_y = 10.1;
  // First reflection is given.
  double next_x     = 1.4, next_y = -9.6;
  // Initial beam slope.
  double slope_beam = (prev_y - next_y) / (prev_x - next_x);
  // Initial beam y-intercept
  double intrc_beam = prev_y;
  double slope_tan, slope_norm;
  double A, B, C;

  // Reflection counter.
  int refls = 0;
  // Simulate reflections until beam exits through gap at (-0.01<=x<=0.01, y=10)
  while (next_y < 9.99 || (next_x > 0.01 || next_x < -0.01)) {
    ++refls;
    printf("Reflection %d at (%f, %f)\n", refls, next_x, next_y);
//    printf("\ty = %fx + %f\n", slope_beam, intrc_beam);

    // Slope of the line tangent to the ellipse at a given point: m = -4x/y
    slope_tan  = -4 * next_x / next_y;
    // Slope of the line normal to the tangent: m = -1 / (-4x/y)
    slope_norm = -1 / slope_tan;
    // Slope of the reflected beam is calculated from the angles:
    // let alpha = angle of beam with x-axis
    // let alpha + beta = angle of normal line with x-axis
    // let alpha + 2 * beta = angle of reflected beam with x-axis
    //  since angle of incidence == angle of reflection, ie. beta is angle of
    //  incidence/reflection.
    // tan(angle) = slope of line making that angle
    // tan(alpha) = slope_beam; alpha = atan(slope_beam)
    // tan(alpha + beta) = slope_normal; alpha + beta = atan(slope_normal)
    //  beta = atan(slope_normal) - atan(slope_beam)
    // tan(alpha + 2*beta) = slope of reflected beam
    // tan(alpha + 2*beta) = tan(atan(slope_beam) + 2*(atan(slope_norm) 
    //                                                  - atan(slope_beam)))
    slope_beam = 
      tan(atan(slope_beam) + 2 * (atan(slope_norm) - atan(slope_beam)));
    // y-intercept of the reflected beam is found by plugging in known point
    intrc_beam = next_y - slope_beam * next_x;

    // Reflected beam: y = slope_beam * x + intrc_beam
    // Ellipse: 4x^2 + y^2 = 100
    // Substitute y and solve for x:
    // 4x^2 + (slope_beam * x + intrc_beam)^2 - 100 = 0
    // 4x^2 + slope_beam^2*x^2 + 2*slope_beam*intrc_beam*x + intrc_beam^2 - 100 = 0
    // (4+slope_beam^2)x^2 + (2*slope_beam*intrc_beam)x + (intrc_beam^2 - 100) = 0
    // Substitutions for quadratic formula
    A = 4 + slope_beam * slope_beam;
    B = 2 * slope_beam * intrc_beam;
    C = intrc_beam * intrc_beam - 100;

    prev_x = next_x;
    prev_y = next_y;

    // From quadratic formula: x = +-sqrt(B^2 - 4*A*C) - B) / 2A
    next_x = (sqrt(B * B - 4 * A * C) - B) / (2 * A);
    // Compare x to previous point. If they are the same, take the other root
    //  of x:
    if (fabs(prev_x - next_x) <= EPS)
      next_x = (-sqrt(B * B - 4 * A * C) - B) / (2 * A);
    // Plug known x into ellipse equation and solve for y:
    // y^2 = 100 - 4x^2; y = +-sqrt(100 - 4x^2)
    next_y = sqrt(100 - 4 * next_x * next_x);
    // Compare slope of reflected beam to the slope produced by the two known
    //  points. If they are different, take the other root of y:
    if (fabs((prev_y - next_y) / (prev_x - next_x) - slope_beam) > EPS)
      next_y = -sqrt(100 - 4 * next_x * next_x);
  }

  printf("%d total reflections, exit at (%f, %f)\n", 
      refls, next_x, next_y);

  return 0;
}
