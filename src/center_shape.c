#include "psolids.h"

/* reposition shape according to 'center' specification */
void center_shape(Psolid *psolid)
{
  int i;

  for (i = 0; i < psolid->nvert; ++i) {
    /* the y and z coordinates of the points of our shape are treated
       as the x and y coordinates of the projection, respectively */
    psolid->pts[i].y += psolid->x;
    psolid->pts[i].z += psolid->y;
  }
}
