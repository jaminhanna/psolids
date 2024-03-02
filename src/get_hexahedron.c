#include "psolids.h"

void get_hexahedron(Psolid *psolid)
{
  psolid->pts[0].x = 0.0 + psolid->elen / 2.0;
  psolid->pts[0].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[0].z = 0.0 + psolid->elen / 2.0;
  psolid->pts[1].x = 0.0 + psolid->elen / 2.0;
  psolid->pts[1].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[1].z = 0.0 + psolid->elen / 2.0;
  psolid->pts[2].x = 0.0 - psolid->elen / 2.0;
  psolid->pts[2].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[2].z = 0.0 + psolid->elen / 2.0;
  psolid->pts[3].x = 0.0 - psolid->elen / 2.0;
  psolid->pts[3].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[3].z = 0.0 + psolid->elen / 2.0;
  psolid->pts[4].x = 0.0 + psolid->elen / 2.0;
  psolid->pts[4].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[4].z = 0.0 - psolid->elen / 2.0;
  psolid->pts[5].x = 0.0 + psolid->elen / 2.0;
  psolid->pts[5].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[5].z = 0.0 - psolid->elen / 2.0;
  psolid->pts[6].x = 0.0 - psolid->elen / 2.0;
  psolid->pts[6].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[6].z = 0.0 - psolid->elen / 2.0;
  psolid->pts[7].x = 0.0 - psolid->elen / 2.0;
  psolid->pts[7].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[7].z = 0.0 - psolid->elen / 2.0;

  psolid->faces[0].pts[0]  = &psolid->pts[0];
  psolid->faces[0].pts[1]  = &psolid->pts[4];
  psolid->faces[0].pts[2]  = &psolid->pts[5];
  psolid->faces[0].pts[3]  = &psolid->pts[1];
  psolid->faces[0].pts[4]  =  NULL;
  psolid->faces[0].sum     =  0.0;
  psolid->faces[0].sum    +=  psolid->pts[0].x;
  psolid->faces[0].sum    +=  psolid->pts[4].x;
  psolid->faces[0].sum    +=  psolid->pts[5].x;
  psolid->faces[0].sum    +=  psolid->pts[1].x;
  psolid->order[0]         = &psolid->faces[0];

  psolid->faces[1].pts[0]  = &psolid->pts[1];
  psolid->faces[1].pts[1]  = &psolid->pts[5];
  psolid->faces[1].pts[2]  = &psolid->pts[6];
  psolid->faces[1].pts[3]  = &psolid->pts[2];
  psolid->faces[1].pts[4]  =  NULL;
  psolid->faces[1].sum     =  0.0;
  psolid->faces[1].sum    +=  psolid->pts[1].x;
  psolid->faces[1].sum    +=  psolid->pts[5].x;
  psolid->faces[1].sum    +=  psolid->pts[6].x;
  psolid->faces[1].sum    +=  psolid->pts[2].x;
  psolid->order[1]         = &psolid->faces[1];

  psolid->faces[2].pts[0]  = &psolid->pts[2];
  psolid->faces[2].pts[1]  = &psolid->pts[6];
  psolid->faces[2].pts[2]  = &psolid->pts[7];
  psolid->faces[2].pts[3]  = &psolid->pts[3];
  psolid->faces[2].pts[4]  =  NULL;
  psolid->faces[2].sum     =  0.0;
  psolid->faces[2].sum    +=  psolid->pts[2].x;
  psolid->faces[2].sum    +=  psolid->pts[6].x;
  psolid->faces[2].sum    +=  psolid->pts[7].x;
  psolid->faces[2].sum    +=  psolid->pts[3].x;
  psolid->order[2]         = &psolid->faces[2];

  psolid->faces[3].pts[0]  = &psolid->pts[3];
  psolid->faces[3].pts[1]  = &psolid->pts[7];
  psolid->faces[3].pts[2]  = &psolid->pts[4];
  psolid->faces[3].pts[3]  = &psolid->pts[0];
  psolid->faces[3].pts[4]  =  NULL;
  psolid->faces[3].sum     =  0.0;
  psolid->faces[3].sum    +=  psolid->pts[3].x;
  psolid->faces[3].sum    +=  psolid->pts[7].x;
  psolid->faces[3].sum    +=  psolid->pts[4].x;
  psolid->faces[3].sum    +=  psolid->pts[0].x;
  psolid->order[3]         = &psolid->faces[3];

  psolid->faces[4].pts[0]  = &psolid->pts[1];
  psolid->faces[4].pts[1]  = &psolid->pts[2];
  psolid->faces[4].pts[2]  = &psolid->pts[3];
  psolid->faces[4].pts[3]  = &psolid->pts[0];
  psolid->faces[4].pts[4]  =  NULL;
  psolid->faces[4].sum     =  0.0;
  psolid->faces[4].sum    +=  psolid->pts[1].x;
  psolid->faces[4].sum    +=  psolid->pts[2].x;
  psolid->faces[4].sum    +=  psolid->pts[3].x;
  psolid->faces[4].sum    +=  psolid->pts[0].x;
  psolid->order[4]         = &psolid->faces[4];

  psolid->faces[5].pts[0]  = &psolid->pts[4];
  psolid->faces[5].pts[1]  = &psolid->pts[7];
  psolid->faces[5].pts[2]  = &psolid->pts[6];
  psolid->faces[5].pts[3]  = &psolid->pts[5];
  psolid->faces[5].pts[4]  =  NULL;
  psolid->faces[5].sum     =  0.0;
  psolid->faces[5].sum    +=  psolid->pts[4].x;
  psolid->faces[5].sum    +=  psolid->pts[7].x;
  psolid->faces[5].sum    +=  psolid->pts[6].x;
  psolid->faces[5].sum    +=  psolid->pts[5].x;
  psolid->order[5]         = &psolid->faces[5];
}
