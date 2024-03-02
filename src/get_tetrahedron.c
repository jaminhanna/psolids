#include <math.h>
#include "psolids.h"

void get_tetrahedron(Psolid *psolid)
{
  double height;

  height = sqrt(2.0/3.0) * psolid->elen;
  psolid->pts[0].x = 0.0 + 2.0 / 3.0 * height;
  psolid->pts[0].y = 0.0;
  psolid->pts[0].z = 0.0 - height / 4.0;
  psolid->pts[1].x = 0.0 - height / 4.0;
  psolid->pts[1].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[1].z = 0.0 - height / 4.0;
  psolid->pts[2].x = 0.0 - height / 4.0;
  psolid->pts[2].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[2].z = 0.0 - height / 4.0;
  psolid->pts[3].x = 0.0;
  psolid->pts[3].y = 0.0;
  psolid->pts[3].z = 0.0 + height * 3.0 / 4.0;

  /* construct faces */
  psolid->faces[0].pts[0]  = &psolid->pts[3];
  psolid->faces[0].pts[1]  = &psolid->pts[0];
  psolid->faces[0].pts[2]  = &psolid->pts[1];
  psolid->faces[0].pts[3]  =  NULL;
  psolid->faces[0].sum     =  0.0;
  psolid->faces[0].sum    +=  psolid->pts[3].x;
  psolid->faces[0].sum    +=  psolid->pts[0].x;
  psolid->faces[0].sum    +=  psolid->pts[1].x;
  psolid->order[0]         = &psolid->faces[0];

  psolid->faces[1].pts[0]  = &psolid->pts[3];
  psolid->faces[1].pts[1]  = &psolid->pts[1];
  psolid->faces[1].pts[2]  = &psolid->pts[2];
  psolid->faces[1].pts[3]  =  NULL;
  psolid->faces[1].sum     =  0.0;
  psolid->faces[1].sum    +=  psolid->pts[3].x;
  psolid->faces[1].sum    +=  psolid->pts[1].x;
  psolid->faces[1].sum    +=  psolid->pts[2].x;
  psolid->order[1]         = &psolid->faces[1];

  psolid->faces[2].pts[0]  = &psolid->pts[3];
  psolid->faces[2].pts[1]  = &psolid->pts[2];
  psolid->faces[2].pts[2]  = &psolid->pts[0];
  psolid->faces[2].pts[3]  =  NULL;
  psolid->faces[2].sum     =  0.0;
  psolid->faces[2].sum    +=  psolid->pts[3].x;
  psolid->faces[2].sum    +=  psolid->pts[2].x;
  psolid->faces[2].sum    +=  psolid->pts[0].x;
  psolid->order[2]         = &psolid->faces[2];

  psolid->faces[3].pts[0]  = &psolid->pts[0];
  psolid->faces[3].pts[1]  = &psolid->pts[1];
  psolid->faces[3].pts[2]  = &psolid->pts[2];
  psolid->faces[3].pts[3]  =  NULL;
  psolid->faces[3].sum     =  0.0;
  psolid->faces[3].sum    +=  psolid->pts[0].x;
  psolid->faces[3].sum    +=  psolid->pts[1].x;
  psolid->faces[3].sum    +=  psolid->pts[2].x;
  psolid->order[3]         = &psolid->faces[3];
}
