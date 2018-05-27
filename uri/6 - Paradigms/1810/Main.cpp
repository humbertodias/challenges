#include <cstdio>
#include <cassert>

#define MAXDAYS 181

#define min(x,y) ((x <= y) ? (x) : (y))

#ifdef DEBUG
#  define D(x) x
#else
#  define D(x)
#endif

int main (void)
{
  FILE* ifs;

  int i, n, t, r;
  int f[MAXDAYS], p[MAXDAYS], h[MAXDAYS], d[MAXDAYS], c[MAXDAYS];
  int H[MAXDAYS], D[MAXDAYS];
  int Inst = 0;

  // assert ((ifs = fopen (IF_NAME, "rt")) != 0);
  ifs = stdin;
  
  while (1) {
    fscanf (ifs, "%d", &n); 
    if (!n) break; assert (n <= MAXDAYS);

    printf ("Instancia #%d\n", ++Inst);
    for (t = 1; t <= n; ++t)
      fscanf (ifs, "%d%d%d%d", &f[t], &p[t], &h[t], &d[t]);

    for (t = 1; t <= n; ++t) {
      c[t] = p[t];
      for (i = t; i <= n; ++i) 
        c[t] += h[i];
    }

    D[0] = 0;
    for (t = 1; t <= n; D[t] = D[t-1] + d[t], ++t);
    for (r = 0, t = 1; t <= n; r += h[t] * D[t], ++t);

    H[0] = 0;
    for (i = 1; i <= n; ++i) {
      H[i] = H[0] + f[1] + c[1] * (D[i] - D[0]);

      for (t = 2; t <= i; ++t)
        H[i] = min (H[i], H[t-1] + f[t] + c[t] * (D[i] - D[t-1]));

      D (printf ("H[%d] = %d\n", i, H[i]));
    }

    printf ("%d\n\n", H[n] - r);
  }

  fclose (ifs);
  return 0;
}