#include "psolids.h"

/* for each face, get the sum of the x coordinates of its vertices, to
   be used to establish a printing order */
void get_sums(Psolid *psolid)
{
  int i, j;

  for (i = 0; i < psolid->nfaces; ++i) {
    psolid->faces[i].sum = 0.0;
    for (j = 0; psolid->faces[i].pts[j] != NULL; ++j) {
      psolid->faces[i].sum += psolid->faces[i].pts[j]->x;
    }
  }
}
