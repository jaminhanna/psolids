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
    printf("(* %d *)   newline poly\n", num);
    /* let shape-specific color take precedence over default colors;
       let face-specific color take precedence over shape-specific
       color and default color */
    if (ps->order[i]->colored == 0)
      printf("(* %d *)   pcfill %.6lf %.6lf %.6lf\n", num, r, g, b);
    /* print user-specified jgraph */
    cmdp = cmd;
    while (*cmdp != '\0') {
      printf("(* %d *)   ", num);
      while (*cmdp != '\n') putchar(*cmdp++);
      putchar(*cmdp++);
    }
    if (ps->order[i]->colored == 1)
      printf("(* %d *)   pcfill %.6lf %.6lf %.6lf\n", num, r, g, b);
    /* print points */
    printf("(* %d *)   pts\n", num);
    for (j = 0; ps->order[i]->pts[j] != NULL; ++j) {
      printf("(* %d *)", num);
      printf(" %18.6lf", ps->order[i]->pts[j]->y);
      printf(" %12.6lf", ps->order[i]->pts[j]->z);
      printf("\n");
    }
    printf("\n");
  }
}
