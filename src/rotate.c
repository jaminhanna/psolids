#include <math.h>
#include "psolids.h"

void roll_shape(Psolid *psolid, double a)
{
  int i;
  double newx, newy, newz;

  for (i = 0; i < psolid->nvert; ++i) {
    newx = newy = newz = 0;

    newx += 1.0 * psolid->pts[i].x;
    newx += 0.0 * psolid->pts[i].y;
    newx += 0.0 * psolid->pts[i].z;

    newy += 0.0    * psolid->pts[i].x;
    newy += cos(a) * psolid->pts[i].y;
    newy -= sin(a) * psolid->pts[i].z;

    newz += 0.0    * psolid->pts[i].x;
    newz += sin(a) * psolid->pts[i].y;
    newz += cos(a) * psolid->pts[i].z;

    psolid->pts[i].x = newx;
    psolid->pts[i].y = newy;
    psolid->pts[i].z = newz;
  }
}

void pitch_shape(Psolid *psolid, double a)
{
  int i;
  double newx, newy, newz;

  for (i = 0; i < psolid->nvert; ++i) {
    newx = newy = newz = 0;

    newx += cos(a) * psolid->pts[i].x;
    newx += 0.0    * psolid->pts[i].y;
    newx += sin(a) * psolid->pts[i].z;

    newy += 0.0 * psolid->pts[i].x;
    newy += 1.0 * psolid->pts[i].y;
    newy += 0.0 * psolid->pts[i].z;

    newz -= sin(a) * psolid->pts[i].x;
    newz += 0.0    * psolid->pts[i].y;
    newz += cos(a) * psolid->pts[i].z;

    psolid->pts[i].x = newx;
    psolid->pts[i].y = newy;
    psolid->pts[i].z = newz;
  }
}

void yaw_shape(Psolid *psolid, double a)
{
  int i;
  double newx, newy, newz;

  for (i = 0; i < psolid->nvert; ++i) {
    newx = newy = newz = 0;

    newx += cos(a) * psolid->pts[i].x;
    newx -= sin(a) * psolid->pts[i].y;
    newx += 0.0    * psolid->pts[i].z;

    newy += sin(a) * psolid->pts[i].x;
    newy += cos(a) * psolid->pts[i].y;
    newy += 0.0    * psolid->pts[i].z;

    newz += 0.0 * psolid->pts[i].x;
    newz += 0.0 * psolid->pts[i].y;
    newz += 1.0 * psolid->pts[i].z;

    psolid->pts[i].x = newx;
    psolid->pts[i].y = newy;
    psolid->pts[i].z = newz;
  }
}
