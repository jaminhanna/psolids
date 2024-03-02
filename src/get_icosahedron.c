#include "psolids.h"

void get_icosahedron(Psolid *psolid)
{
  /* get the points corresponding to the rectangle in the xy plane */
  psolid->pts[ 0].x = 0.0 + psolid->elen / 2.0;
  psolid->pts[ 0].y = 0.0 + psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 0].z = 0.0;
  psolid->pts[ 1].x = 0.0 + psolid->elen / 2.0;
  psolid->pts[ 1].y = 0.0 - psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 1].z = 0.0;
  psolid->pts[ 2].x = 0.0 - psolid->elen / 2.0;
  psolid->pts[ 2].y = 0.0 - psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 2].z = 0.0;
  psolid->pts[ 3].x = 0.0 - psolid->elen / 2.0;
  psolid->pts[ 3].y = 0.0 + psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 3].z = 0.0;

  /* get the points corresponding to the rectangle in the xz plane */
  psolid->pts[ 4].x = 0.0 + psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 4].y = 0.0;
  psolid->pts[ 4].z = 0.0 + psolid->elen / 2.0;
  psolid->pts[ 5].x = 0.0 + psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 5].y = 0.0;
  psolid->pts[ 5].z = 0.0 - psolid->elen / 2.0;
  psolid->pts[ 6].x = 0.0 - psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 6].y = 0.0;
  psolid->pts[ 6].z = 0.0 - psolid->elen / 2.0;
  psolid->pts[ 7].x = 0.0 - psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 7].y = 0.0;
  psolid->pts[ 7].z = 0.0 + psolid->elen / 2.0;

  /* get the points corresponding to the rectangle in the yz plane */
  psolid->pts[ 8].x = 0.0;
  psolid->pts[ 8].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[ 8].z = 0.0 + psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[ 9].x = 0.0;
  psolid->pts[ 9].y = 0.0 + psolid->elen / 2.0;
  psolid->pts[ 9].z = 0.0 - psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[10].x = 0.0;
  psolid->pts[10].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[10].z = 0.0 - psolid->elen / 2.0 * GOLDEN_RATIO;
  psolid->pts[11].x = 0.0;
  psolid->pts[11].y = 0.0 - psolid->elen / 2.0;
  psolid->pts[11].z = 0.0 + psolid->elen / 2.0 * GOLDEN_RATIO;

  /* construct faces */
  psolid->faces[ 0].pts[0]  = &psolid->pts[ 4];
  psolid->faces[ 0].pts[1]  = &psolid->pts[11];
  psolid->faces[ 0].pts[2]  = &psolid->pts[ 8];
  psolid->faces[ 0].pts[3]  =  NULL;
  psolid->faces[ 0].sum     =  0.0;
  psolid->faces[ 0].sum    +=  psolid->pts[ 4].x;
  psolid->faces[ 0].sum    +=  psolid->pts[11].x;
  psolid->faces[ 0].sum    +=  psolid->pts[ 8].x;
  psolid->order[ 0]         = &psolid->faces[ 0];

  psolid->faces[ 1].pts[0]  = &psolid->pts[ 4];
  psolid->faces[ 1].pts[1]  = &psolid->pts[ 8];
  psolid->faces[ 1].pts[2]  = &psolid->pts[ 0];
  psolid->faces[ 1].pts[3]  =  NULL;
  psolid->faces[ 1].sum     =  0.0;
  psolid->faces[ 1].sum    +=  psolid->pts[ 4].x;
  psolid->faces[ 1].sum    +=  psolid->pts[ 8].x;
  psolid->faces[ 1].sum    +=  psolid->pts[ 0].x;
  psolid->order[ 1]         = &psolid->faces[ 1];

  psolid->faces[ 2].pts[0]  = &psolid->pts[ 4];
  psolid->faces[ 2].pts[1]  = &psolid->pts[ 0];
  psolid->faces[ 2].pts[2]  = &psolid->pts[ 5];
  psolid->faces[ 2].pts[3]  =  NULL;
  psolid->faces[ 2].sum     =  0.0;
  psolid->faces[ 2].sum    +=  psolid->pts[ 4].x;
  psolid->faces[ 2].sum    +=  psolid->pts[ 0].x;
  psolid->faces[ 2].sum    +=  psolid->pts[ 5].x;
  psolid->order[ 2]         = &psolid->faces[ 2];

  psolid->faces[ 3].pts[0]  = &psolid->pts[ 4];
  psolid->faces[ 3].pts[1]  = &psolid->pts[ 5];
  psolid->faces[ 3].pts[2]  = &psolid->pts[ 1];
  psolid->faces[ 3].pts[3]  =  NULL;
  psolid->faces[ 3].sum     =  0.0;
  psolid->faces[ 3].sum    +=  psolid->pts[ 4].x;
  psolid->faces[ 3].sum    +=  psolid->pts[ 5].x;
  psolid->faces[ 3].sum    +=  psolid->pts[ 1].x;
  psolid->order[ 3]         = &psolid->faces[ 3];

  psolid->faces[ 4].pts[0]  = &psolid->pts[ 4];
  psolid->faces[ 4].pts[1]  = &psolid->pts[ 1];
  psolid->faces[ 4].pts[2]  = &psolid->pts[11];
  psolid->faces[ 4].pts[3]  =  NULL;
  psolid->faces[ 4].sum     =  0.0;
  psolid->faces[ 4].sum    +=  psolid->pts[ 4].x;
  psolid->faces[ 4].sum    +=  psolid->pts[ 1].x;
  psolid->faces[ 4].sum    +=  psolid->pts[11].x;
  psolid->order[ 4]         = &psolid->faces[ 4];

  psolid->faces[ 5].pts[0]  = &psolid->pts[ 2];
  psolid->faces[ 5].pts[1]  = &psolid->pts[11];
  psolid->faces[ 5].pts[2]  = &psolid->pts[ 1];
  psolid->faces[ 5].pts[3]  =  NULL;
  psolid->faces[ 5].sum     =  0.0;
  psolid->faces[ 5].sum    +=  psolid->pts[ 2].x;
  psolid->faces[ 5].sum    +=  psolid->pts[11].x;
  psolid->faces[ 5].sum    +=  psolid->pts[ 1].x;
  psolid->order[ 5]         = &psolid->faces[ 5];

  psolid->faces[ 6].pts[0]  = &psolid->pts[ 2];
  psolid->faces[ 6].pts[1]  = &psolid->pts[ 1];
  psolid->faces[ 6].pts[2]  = &psolid->pts[10];
  psolid->faces[ 6].pts[3]  =  NULL;
  psolid->faces[ 6].sum     =  0.0;
  psolid->faces[ 6].sum    +=  psolid->pts[ 2].x;
  psolid->faces[ 6].sum    +=  psolid->pts[ 1].x;
  psolid->faces[ 6].sum    +=  psolid->pts[10].x;
  psolid->order[ 6]         = &psolid->faces[ 6];

  psolid->faces[ 7].pts[0]  = &psolid->pts[ 2];
  psolid->faces[ 7].pts[1]  = &psolid->pts[10];
  psolid->faces[ 7].pts[2]  = &psolid->pts[ 6];
  psolid->faces[ 7].pts[3]  =  NULL;
  psolid->faces[ 7].sum     =  0.0;
  psolid->faces[ 7].sum    +=  psolid->pts[ 2].x;
  psolid->faces[ 7].sum    +=  psolid->pts[10].x;
  psolid->faces[ 7].sum    +=  psolid->pts[ 6].x;
  psolid->order[ 7]         = &psolid->faces[ 7];

  psolid->faces[ 8].pts[0]  = &psolid->pts[ 2];
  psolid->faces[ 8].pts[1]  = &psolid->pts[ 6];
  psolid->faces[ 8].pts[2]  = &psolid->pts[ 7];
  psolid->faces[ 8].pts[3]  =  NULL;
  psolid->faces[ 8].sum     =  0.0;
  psolid->faces[ 8].sum    +=  psolid->pts[ 2].x;
  psolid->faces[ 8].sum    +=  psolid->pts[ 6].x;
  psolid->faces[ 8].sum    +=  psolid->pts[ 7].x;
  psolid->order[ 8]         = &psolid->faces[ 8];

  psolid->faces[ 9].pts[0]  = &psolid->pts[ 2];
  psolid->faces[ 9].pts[1]  = &psolid->pts[ 7];
  psolid->faces[ 9].pts[2]  = &psolid->pts[11];
  psolid->faces[ 9].pts[3]  =  NULL;
  psolid->faces[ 9].sum     =  0.0;
  psolid->faces[ 9].sum    +=  psolid->pts[ 2].x;
  psolid->faces[ 9].sum    +=  psolid->pts[ 7].x;
  psolid->faces[ 9].sum    +=  psolid->pts[11].x;
  psolid->order[ 9]         = &psolid->faces[ 9];

  psolid->faces[10].pts[0]  = &psolid->pts[ 3];
  psolid->faces[10].pts[1]  = &psolid->pts[ 8];
  psolid->faces[10].pts[2]  = &psolid->pts[ 7];
  psolid->faces[10].pts[3]  =  NULL;
  psolid->faces[10].sum     =  0.0;
  psolid->faces[10].sum    +=  psolid->pts[ 3].x;
  psolid->faces[10].sum    +=  psolid->pts[ 8].x;
  psolid->faces[10].sum    +=  psolid->pts[ 7].x;
  psolid->order[10]         = &psolid->faces[10];

  psolid->faces[11].pts[0]  = &psolid->pts[ 3];
  psolid->faces[11].pts[1]  = &psolid->pts[ 7];
  psolid->faces[11].pts[2]  = &psolid->pts[ 6];
  psolid->faces[11].pts[3]  =  NULL;
  psolid->faces[11].sum     =  0.0;
  psolid->faces[11].sum    +=  psolid->pts[ 3].x;
  psolid->faces[11].sum    +=  psolid->pts[ 7].x;
  psolid->faces[11].sum    +=  psolid->pts[ 6].x;
  psolid->order[11]         = &psolid->faces[11];

  psolid->faces[12].pts[0]  = &psolid->pts[ 3];
  psolid->faces[12].pts[1]  = &psolid->pts[ 6];
  psolid->faces[12].pts[2]  = &psolid->pts[ 9];
  psolid->faces[12].pts[3]  =  NULL;
  psolid->faces[12].sum     =  0.0;
  psolid->faces[12].sum    +=  psolid->pts[ 3].x;
  psolid->faces[12].sum    +=  psolid->pts[ 6].x;
  psolid->faces[12].sum    +=  psolid->pts[ 9].x;
  psolid->order[12]         = &psolid->faces[12];

  psolid->faces[13].pts[0]  = &psolid->pts[ 3];
  psolid->faces[13].pts[1]  = &psolid->pts[ 9];
  psolid->faces[13].pts[2]  = &psolid->pts[ 0];
  psolid->faces[13].pts[3]  =  NULL;
  psolid->faces[13].sum     =  0.0;
  psolid->faces[13].sum    +=  psolid->pts[ 3].x;
  psolid->faces[13].sum    +=  psolid->pts[ 9].x;
  psolid->faces[13].sum    +=  psolid->pts[ 0].x;
  psolid->order[13]         = &psolid->faces[13];

  psolid->faces[14].pts[0]  = &psolid->pts[ 3];
  psolid->faces[14].pts[1]  = &psolid->pts[ 0];
  psolid->faces[14].pts[2]  = &psolid->pts[ 8];
  psolid->faces[14].pts[3]  =  NULL;
  psolid->faces[14].sum     =  0.0;
  psolid->faces[14].sum    +=  psolid->pts[ 3].x;
  psolid->faces[14].sum    +=  psolid->pts[ 0].x;
  psolid->faces[14].sum    +=  psolid->pts[ 8].x;
  psolid->order[14]         = &psolid->faces[14];

  psolid->faces[15].pts[0]  = &psolid->pts[ 0];
  psolid->faces[15].pts[1]  = &psolid->pts[ 9];
  psolid->faces[15].pts[2]  = &psolid->pts[ 5];
  psolid->faces[15].pts[3]  =  NULL;
  psolid->faces[15].sum     =  0.0;
  psolid->faces[15].sum    +=  psolid->pts[ 0].x;
  psolid->faces[15].sum    +=  psolid->pts[ 9].x;
  psolid->faces[15].sum    +=  psolid->pts[ 5].x;
  psolid->order[15]         = &psolid->faces[15];

  psolid->faces[16].pts[0]  = &psolid->pts[10];
  psolid->faces[16].pts[1]  = &psolid->pts[ 1];
  psolid->faces[16].pts[2]  = &psolid->pts[ 5];
  psolid->faces[16].pts[3]  =  NULL;
  psolid->faces[16].sum     =  0.0;
  psolid->faces[16].sum    +=  psolid->pts[10].x;
  psolid->faces[16].sum    +=  psolid->pts[ 1].x;
  psolid->faces[16].sum    +=  psolid->pts[ 5].x;
  psolid->order[16]         = &psolid->faces[16];

  psolid->faces[17].pts[0]  = &psolid->pts[10];
  psolid->faces[17].pts[1]  = &psolid->pts[ 5];
  psolid->faces[17].pts[2]  = &psolid->pts[ 9];
  psolid->faces[17].pts[3]  =  NULL;
  psolid->faces[17].sum     =  0.0;
  psolid->faces[17].sum    +=  psolid->pts[10].x;
  psolid->faces[17].sum    +=  psolid->pts[ 5].x;
  psolid->faces[17].sum    +=  psolid->pts[ 9].x;
  psolid->order[17]         = &psolid->faces[17];

  psolid->faces[18].pts[0]  = &psolid->pts[10];
  psolid->faces[18].pts[1]  = &psolid->pts[ 9];
  psolid->faces[18].pts[2]  = &psolid->pts[ 6];
  psolid->faces[18].pts[3]  =  NULL;
  psolid->faces[18].sum     =  0.0;
  psolid->faces[18].sum     =  psolid->pts[10].x;
  psolid->faces[18].sum     =  psolid->pts[ 9].x;
  psolid->faces[18].sum     =  psolid->pts[ 6].x;
  psolid->order[18]         = &psolid->faces[18];

  psolid->faces[19].pts[0]  = &psolid->pts[11];
  psolid->faces[19].pts[1]  = &psolid->pts[ 7];
  psolid->faces[19].pts[2]  = &psolid->pts[ 8];
  psolid->faces[19].pts[3]  =  NULL;
  psolid->faces[19].sum     =  0.0;
  psolid->faces[19].sum    +=  psolid->pts[11].x;
  psolid->faces[19].sum    +=  psolid->pts[ 7].x;
  psolid->faces[19].sum    +=  psolid->pts[ 8].x;
  psolid->order[19]         = &psolid->faces[19];
}
