#include <stdio.h>
#include <ctype.h>
#include "psolids.h"

/* read a word into buf and return its length */
int getword(void)
{
  int ch;
  size_t len;

  /* consume all preceding whitespace */
  while (isspace(ch = fgetc(stream))) ;
  if (ungetc(ch, stream) == EOF) return 0;

  len = 0;
  while (!isspace(ch = fgetc(stream)) && ch != EOF && len < BUFSIZ-1) {
    buf[len++] = ch;
  }
  buf[len] = '\0';

  return len;
}
