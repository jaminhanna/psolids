#include <stdio.h>

/* first twenty indeces (0-19) used to process 'faces' input */
#define MARKTYPE      20
#define MARKSIZE      21
#define MROTATE       22
#define GRAY          23
#define COLOR         24
#define FILL          25
#define CFILL         26
#define PATTERN       27
#define PFILL         28
#define PCFILL        29
#define PPATTERN      30
#define LINETYPE      31
#define LINETHICKNESS 32
#define CLIP          33
#define NOCLIP        34

#define SENTINEL      -1
#define MAXPOINTS     20
#define MAXFACES      20
#define NCOMMANDS     15

#define GOLDEN_RATIO  1.618033988749 /* ... */

char                    *name; /* "stdin" or name of file */
char              buf[BUFSIZ]; /* buffer used to parse input */
char used[MAXFACES+NCOMMANDS];
FILE                  *stream;

typedef struct {
  double        x, y, z;
} Point;

typedef struct {
  int                id;
  double            sum;
  int           colored;
  double        r, g, b;
  Point         *pts[6];
} Face;

typedef struct {
  int                id;
  int            nfaces;
  int             nvert;
  double           elen;
  double           x, y;
  double           roll;
  double          pitch;
  double            yaw;
  Point  pts[MAXPOINTS];
  Face  faces[MAXFACES];
  Face *order[MAXFACES]; /* holds faces in printing order */
} Psolid;

int    getword          (void);
void   getjgraph        (char *cmd,   size_t *index);
double degtorad         (double deg);
void   get_tetrahedron  (Psolid *ps);
void   get_hexahedron   (Psolid *ps);
void   get_octahedron   (Psolid *ps);
void   get_dodecahedron (Psolid *ps);
void   get_icosahedron  (Psolid *ps);
void   roll_shape       (Psolid *ps,  double a);
void   pitch_shape      (Psolid *ps,  double a);
void   yaw_shape        (Psolid *ps,  double a);
void   sort_faces       (Face   *f[], int start, int size);
void   get_sums         (Psolid *ps);
void   center_shape     (Psolid *ps);
void   print_shape      (Psolid *ps, char *cmd, int nshapes);
