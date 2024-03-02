#include "psolids.h"

/* arrange faces in the appropriate order for printing */
void sort_faces(Face *f[], int start, int size)
{
  int    i, j, k;
  int      index;
  double     avg;
  double     min;
  double    diff;
  Face      *tmp;
  int     ind[3];

  /* no need to swap if size is less than two */
  if (size < 2) return;
  /* if considering two elements, swap manually if necessary */
  if (size == 2) {
    if (f[start]->sum > f[start+1]->sum) {
      tmp        = f[start];
      f[start]   = f[start+1];
      f[start+1] = tmp;
    }
    return;
  }

  /* find element to be the pivot */
  avg  = 0.0;
  avg += f[start]->sum;
  avg += f[start+size/2]->sum;
  avg += f[start+size-1]->sum;
  avg /= 3.0;

  ind[0] = start;
  ind[1] = start+size/2;
  ind[2] = start+size-1;

  /* use the median of three method to determine the pivot */
  min    = avg+1;
  index  = start;
  for (i = 0; i < 3; ++i) {
    if (f[ind[i]]->sum > avg) diff = f[ind[i]]->sum - avg;
    else                      diff = avg - f[ind[i]]->sum;
    if (diff <= min) {
      min   = diff;
      index = ind[i];
    }
  }

  /* swap pivot with first element if the two are not equal */
  if (f[start]->sum != f[index]->sum) {
    tmp      = f[start];
    f[start] = f[index];
    f[index] = tmp;
  }

  /* partition the portion of the vector under consideration */
  j = start+1;
  k = start+size-1;
  while (j < k) {
    while (f[j]->sum < f[start]->sum && j != start+size-1) ++j;
    while (f[k]->sum > f[start]->sum && k != start)        --k;

    /* add a comment */
    if (j < k) {
      tmp  = f[j];
      f[j] = f[k];
      f[k] = tmp;
      ++j;
      --k;
    }
  }

  /* add a comment */
  if (j == k && f[j]->sum <= f[start]->sum) ++j;

  /* add a comment */
  tmp      = f[start];
  f[start] = f[j-1];
  f[j-1]   = tmp;

  /* recursively sort the left and right partitions */
  sort_faces(f, start,    j-start-1);
  sort_faces(f,     j, start+size-j);
}
