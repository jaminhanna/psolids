#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "psolids.h"

int main(int argc, char *argv[])
{
  int          i, j, n;
  int              len; /* length of word parsed by getword */
  size_t         index; /* index into jgraph command string */
  int            isdeg; /* whether rotational value is in degrees */
  int          nshapes;
  double       r, g, b;
  double           dbl;
  double      *dp, *rp;
  char    cmd [BUFSIZ]; /* jgraph command string */
  int    enc[MAXFACES]; /* enc[j] == 1 if face j has been colored */
  char        *keyword;
  Psolid            ps;

  isdeg = nshapes = 0;
  used[MAXFACES+NCOMMANDS-1] = SENTINEL;
  /* read from stdin or specified files */
  switch (argc) {
    case 1  : name = "stdin"; stream = stdin;                 break;
    default : name = argv[1]; stream = fopen(argv[1],   "r"); break;
  }
  for (i = 1; stream != NULL; stream = fopen(argv[i++], "r")) {
    if ((len = getword()) == 0) { /* no word to read */
      if (i == argc) return EXIT_SUCCESS; /* no more files */
      continue; /* ignore empty files */
    }
    if (strcmp(buf, "newshape") != 0) {
      fprintf(stderr, "%s: 'newshape' keyword must begin input\n",
              name);
      return EXIT_FAILURE;
    }

    while (len > 0) { /* there is still a word to process */

      if (strcmp(buf, "newshape") == 0) {
        if (getword()                   == 0 ||
            (strcmp(buf, "tetrahedron") != 0 &&
            strcmp(buf,   "hexahedron") != 0 &&
            strcmp(buf,   "octahedron") != 0 &&
            strcmp(buf, "dodecahedron") != 0 &&
            strcmp(buf,  "icosahedron") != 0)) {
          fprintf(stderr, "%s: Invalid shape name: %s\n", name, buf);
          return EXIT_FAILURE;
        }
        switch (buf[0]) {
          case 't' : ps.id = 't'; ps.nfaces =  4; ps.nvert =  4; break;
          case 'h' : ps.id = 'h'; ps.nfaces =  6; ps.nvert =  8; break;
          case 'o' : ps.id = 'o'; ps.nfaces =  8; ps.nvert =  6; break;
          case 'd' : ps.id = 'd'; ps.nfaces = 12; ps.nvert = 20; break;
          case 'i' : ps.id = 'i'; ps.nfaces = 20; ps.nvert = 12; break;
        }
        /* set default values of shape */
        ps.elen  = 72.0; /* 72 postscript units == 1 inch */
        ps.x     =  0.0;
        ps.y     =  0.0;
        ps.roll  =  0.0;
        ps.pitch =  0.0;
        ps.yaw   =  0.0;
        /* let default face colors be random */
        srand48((long) time(NULL));
        for (j = 0; j < ps.nfaces; ++j) {
          ps.faces[j].r = drand48();
          ps.faces[j].g = drand48();
          ps.faces[j].b = drand48();
          ps.faces[j].colored = 0;
        }
        /* (re)set variables to read in shape */
        ++nshapes;
        cmd[0] = '\0';
        j = index = 0;
        while (used[j] != SENTINEL) used[j++] = 0;
      }

      while ((len = getword()) != 0 && strcmp(buf, "newshape") != 0) {
        if (strcmp(buf, "edgelength") == 0) {
          /* a double should follow 'edgelength' */
          if (getword() == 0 || sscanf(buf, "%lf", &ps.elen) == 0) {
            fprintf(stderr, "%s: A double must follow 'edgelength'\n",
                    name);
            return EXIT_FAILURE;
          }
          /* make sure value specified is positive */
          if (ps.elen <= 0.0) {
            fprintf(stderr, "%s: Double following 'edgelength' must be"
                            " positive\n", name);
            return EXIT_FAILURE;
          }
        } else if (strcmp(buf, "center") == 0) {
          /* two doubles should follow 'center' */
          for (j = 0, dp = &ps.x; j < 2; ++j, dp = &ps.y) {
            if (getword() == 0 || sscanf(buf, "%lf", dp) == 0) {
              fprintf(stderr, "%s: Two doubles must follow 'center'\n",
                      name);
              return EXIT_FAILURE;
            }
          }
        } else if (strcmp(buf,  "roll") == 0 ||
                   strcmp(buf, "pitch") == 0 ||
                   strcmp(buf,   "yaw") == 0) {
          switch (buf[0]) {
            case 'r' : keyword =  "roll"; rp =  &ps.roll; break;
            case 'p' : keyword = "pitch"; rp = &ps.pitch; break;
            case 'y' : keyword =   "yaw"; rp =   &ps.yaw; break;
          }
          if (getword()              == 0 ||
              strcmp(buf, "degrees") == 0 ||
              strcmp(buf, "radians") == 0) {
            /* get whether degrees or radians */
            if (buf[0] == 'd') isdeg = 1;
            /* a double should follow 'degrees' or 'radians' */
            if (getword() == 0 || sscanf(buf, "%lf", rp) == 0) {
              fprintf(stderr, "%s: A double must follow '%s' token\n",
                      name, (isdeg == 1) ? "degrees" : "radians");
              return EXIT_FAILURE;
            }
            /* convert degrees to radians */
            if (isdeg == 1) { *rp = degtorad(*rp); isdeg = 0; }
          } else if (sscanf(buf, "%lf", rp) != 1) {
            fprintf(stderr, "%s: 'degrees' or 'radians' or a double"
                            " must follow '%s'\n", name, keyword);
            return EXIT_FAILURE;
          }
        } else if (strcmp(buf, "faces") == 0) {
          /* get face ids */
          j = 0;
          while (getword() != 0 && sscanf(buf, "%d", &n) != 0) {
            /* error check face id */
            sscanf(buf, "%lf", &dbl);
            if (dbl != n || n < 0 || n >= ps.nfaces) {
              fprintf(stderr, "%s: Invalid face id: %s\n", name, buf);
              return EXIT_FAILURE;
            }
            /* only store unique face ids */
            if (used[n] == 0) {
              ++used[n];
              enc[j++] = n;
            }
          }
          /* error if no face id was specified */
          if (j == 0) {
            fprintf(stderr, "%s: At least one face id must follow"
                            " 'faces'\n", name);
            return EXIT_FAILURE;
          }
          /* error if the current word is not 'color' */
          if (strcmp(buf, "color") != 0) {
            fprintf(stderr, "%s: 'color' must accompany 'faces'\n",
                    name);
            return EXIT_FAILURE;
          }
          /* get r g b values */
          if (getword() == 0 || sscanf(buf, "%lf", &r) == 0 ||
              getword() == 0 || sscanf(buf, "%lf", &g) == 0 ||
              getword() == 0 || sscanf(buf, "%lf", &b) == 0) {
            fprintf(stderr, "%s: rgb values must follow 'color'\n",
                    name);
            return EXIT_FAILURE;
          }
          /* rgb values must lie in the interval [0.0, 1.0] */
          if (r < 0.0 || g < 0.0 || b < 0.0) {
            fprintf(stderr, "%s: rgb values must lie in the interval"
                            " [0.0, 1.0]\n", name);
            return EXIT_FAILURE;
          }
          /* initialize the r g b fields of the faces specified */
          enc[j] = SENTINEL;
          for (j = 0; enc[j] != SENTINEL; ++j) {
            ps.faces[enc[j]].r = r;
            ps.faces[enc[j]].g = g;
            ps.faces[enc[j]].b = b;
            ps.faces[enc[j]].colored = 1;
          }
        } else { /* word is either jgraph or invalid input */
          getjgraph(cmd, &index);
        }
      }

      /* build the appropriate shape */
      switch (ps.id) {
        case 't' :  get_tetrahedron(&ps); break;
        case 'h' :   get_hexahedron(&ps); break;
        case 'o' :   get_octahedron(&ps); break;
        case 'd' : get_dodecahedron(&ps); break;
        case 'i' :  get_icosahedron(&ps); break;
      }
      /* perform necessary rotations */
      if (ps.roll  != 0.0)  roll_shape(&ps,  ps.roll);
      if (ps.pitch != 0.0) pitch_shape(&ps, -ps.pitch);
      if (ps.yaw   != 0.0)   yaw_shape(&ps,   -ps.yaw);
      /* determine the positions of the faces, sort them according to
         their positions, center the shape, and print */
      get_sums    (&ps);
      sort_faces  ((Face **) &ps.order, 0, ps.nfaces);
      center_shape(&ps);
      print_shape (&ps, cmd, nshapes);
    }

    fclose(stream);
    if (i == argc) return EXIT_SUCCESS;
    name = argv[i]; /* get name of next file */
  }
}
