#include <stdio.h>
#include "psolids.h"

/* print shape specifications in jgraph */
void print_shape(Psolid *ps, char *cmd, int num)
{
  int       i, j;
  double r, g, b;
  char     *cmdp;

  /* print shape face by face */
  for (i = 0; i < ps->nfaces; ++i) {
    r = ps->order[i]->r;
    g = ps->order[i]->g;
    b = ps->order[i]->b;
   printf("(* %d,%d,%d *)", num, ps->order[i]->id, i);
   printf("   newline poly\n");
    /* let shape-specific color take precedence over default colors;
       let face-specific color take precedence over shape-specific
       color and default color */
    if (ps->order[i]->colored == 0) {
      printf("(* %d,%d,%d *)", num, ps->order[i]->id, i);
      printf("   pcfill %.6lf %.6lf %.6lf\n", r, g, b);
    }
    /* print user-specified jgraph */
    cmdp = cmd;
    while (*cmdp != '\0') {
      printf("(* %d,%d,%d *)   ", num, ps->order[i]->id, i);
      while (*cmdp != '\n') putchar(*cmdp++);
      putchar(*cmdp++);
    }
    if (ps->order[i]->colored == 1) {
      printf("(* %d,%d,%d *)", num, ps->order[i]->id, i);
      printf("   pcfill %.6lf %.6lf %.6lf\n", r, g, b);
    }
    /* print points */
    printf("(* %d,%d,%d *)   pts\n", num, ps->order[i]->id, i);
    for (j = 0; ps->order[i]->pts[j] != NULL; ++j) {
      printf("(* %d,%d,%d *)", num, ps->order[i]->id, i);
      printf(" %18.6lf", ps->order[i]->pts[j]->y);
      printf(" %12.6lf", ps->order[i]->pts[j]->z);
      printf("\n");
    }
    printf("\n");
  }
}
