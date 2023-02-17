#include "mockup.h"

#if SENSOR_MOCKUP_DEMO
double __dRandomT(double t)
{
  double d1 = t + 0.29839;
  double d2 = 3 * t - 0.99447;
  double d3 = 5 * t + 0.88257;
  double d4 = 7 * t - 0.28234;
  return (sin(d1) + sin(d2) + sin(d3) + sin(d4)) * 0.3325;
}
#endif