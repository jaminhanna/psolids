#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psolids.h"

/* parse jgraph command to be placed in command string */
void getjgraph(char *cmd, size_t *index)
{
  int      i, len;
  int       keyid;
  int    ndoubles; /* doubles required by keyword */
  int    badtoken; /* used to error check keywords requiring tokens */
  double      dbl;
  char       *msg; /* error message */
  char   *keyword;
  char     *token;

  badtoken = 0;
  if (strcmp(buf,                   "marktype") == 0) {
    keyword =      "marktype";
    keyid   =       MARKTYPE ;
  } else if (strcmp(buf,            "marksize") == 0) {
    keyword =      "marksize";
    keyid   =       MARKSIZE ;
  } else if (strcmp(buf,             "mrotate") == 0) {
    keyword =       "mrotate";
    keyid   =        MROTATE ;
  } else if (strcmp(buf,                "gray") == 0) {
    keyword =          "gray";
    keyid   =           GRAY ;
  } else if (strcmp(buf,               "color") == 0) {
    keyword =         "color";
    keyid   =          COLOR ;
  } else if (strcmp(buf,                "fill") == 0) {
    keyword =          "fill";
    keyid   =           FILL ;
  } else if (strcmp(buf,               "cfill") == 0) {
    keyword =         "cfill";
    keyid   =          CFILL ;
  } else if (strcmp(buf,             "pattern") == 0) {
    keyword =       "pattern";
    keyid   =        PATTERN ;
  } else if (strcmp(buf,               "pfill") == 0) {
    keyword =         "pfill";
    keyid   =          PFILL ;
  } else if (strcmp(buf,              "pcfill") == 0) {
    keyword =        "pcfill";
    keyid   =         PCFILL ;
  } else if (strcmp(buf,            "ppattern") == 0) {
    keyword =      "ppattern";
    keyid   =       PPATTERN ;
  } else if (strcmp(buf,            "linetype") == 0) {
    keyword =      "linetype";
    keyid   =       LINETYPE ;
  } else if (strcmp(buf,       "linethickness") == 0) {
    keyword = "linethickness";
    keyid   =  LINETHICKNESS ;
  } else if (strcmp(buf,                "clip") == 0) {
    keyword =          "clip";
    keyid   =           CLIP ;
  } else if (strcmp(buf,              "noclip") == 0) {
    keyword =        "noclip";
    keyid   =         NOCLIP ;
  } else {
    fprintf(stderr, "%s: Unrecognized keyword: %s\n", name, buf);
    exit(EXIT_FAILURE);
  }

  switch (keyid) {
    case      MARKTYPE : if (getword()               == 0 ||
                             (strcmp(buf,  "circle") != 0 &&
                             strcmp(buf,      "box") != 0 &&
                             strcmp(buf,  "diamond") != 0 &&
                             strcmp(buf, "triangle") != 0 &&
                             strcmp(buf,        "x") != 0 &&
                             strcmp(buf,    "cross") != 0 &&
                             strcmp(buf,  "ellipse") != 0 &&
                             strcmp(buf,     "none") != 0)) {
                           badtoken = 1; break;
                         }
                         ndoubles = 0; break;
    case      LINETYPE : if (getword()                     == 0 ||
                             (strcmp(buf,         "solid") != 0 &&
                             strcmp(buf,         "dotted") != 0 &&
                             strcmp(buf,         "dashed") != 0 &&
                             strcmp(buf,       "longdash") != 0 &&
                             strcmp(buf,        "dotdash") != 0 &&
                             strcmp(buf,     "dotdotdash") != 0 &&
                             strcmp(buf, "dotdotdashdash") != 0 &&
                             strcmp(buf,           "none") != 0)) {
                           badtoken = 1; break;
                         }
                         ndoubles = 0; break;
    case       PATTERN :
    case      PPATTERN : if (getword()              == 0 ||
                             (strcmp(buf,  "solid") != 0 &&
                             strcmp(buf,  "stripe") != 0 &&
                             strcmp(buf, "estripe") != 0)) {
                           badtoken = 1; break;
                         }
                         /* no doubles follow the 'solid' token */
                         if (strcmp(buf, "solid") == 0) {
                           ndoubles = 0;
                           break;
                         }
    case       MROTATE :
    case          GRAY :
    case          FILL :
    case         PFILL :
    case LINETHICKNESS : ndoubles = 1; break;
    case      MARKSIZE : ndoubles = 2; break;
    case         COLOR :
    case         CFILL :
    case        PCFILL : ndoubles = 3; break;
    case          CLIP :
    case        NOCLIP : ndoubles = 0; break;
  }
  if (used[keyid]++) {
    msg = "%s: '%s' specified twice for single shape\n";
    sprintf(buf, msg, name, keyword);
    fprintf(stderr, "%s", buf);
    exit(EXIT_FAILURE);
  }
  if (badtoken == 1) {
    fprintf(stderr, "Bad token for '%s': %s\n", keyword, buf);
    exit(EXIT_FAILURE);
  }
  /* begin adding words to command string */
  strcpy(cmd+*index, keyword);
  *index += strlen(keyword);
  /* add token to command string if there is one */
  if (keyid == MARKTYPE || keyid == LINETYPE ||
      keyid ==  PATTERN || keyid == PPATTERN) {
    cmd[(*index)++] = ' ';
    strcpy(cmd+*index, buf);
    *index += strlen(buf);
  }
  /* get doubles needed for command */
  for (i = 0; i < ndoubles; ++i) {
    if ((len = getword())        == 0 ||
        sscanf(buf, "%lf", &dbl) == 0) {
      /* print appropriate error message */
      switch (keyid) {
        case  PATTERN :
        case PPATTERN : msg = "%s: A double must follow '%s %s'\n";
                        sprintf(buf, msg, name, keyword, token);
                        fprintf(stderr, "%s", buf);
                        exit(EXIT_FAILURE);
        default       : msg = "%s: %d double%s must follow '%s'\n";
                        sprintf(buf, msg, name, ndoubles,
                                          (ndoubles > 1) ? "s" : "",
                                          keyword);
                        fprintf(stderr, "%s", buf);
                        exit(EXIT_FAILURE);
      }
    }
    cmd[(*index)++] = ' ';
    strcpy(cmd+*index, buf);
    *index += strlen(buf);
  }
  cmd[(*index)++] = '\n'; /* put each command on its own line */
  cmd[*index] = '\0';
}
