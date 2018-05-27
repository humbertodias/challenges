#include <stdio.h>
#include <string.h>

FILE *in;
char fz[1024][128], z1[128], z2[128], i1[128], i2[128], ns[128];
int mf, min, max;

int add(char *res, char *z1, char *z2)
{
  int c=0;
  int i;
  res[127] = 0;
  for(i=126; i>=0; i--)
    {
      res[i] = z1[i]+z2[i]-'0'+c;
      if (res[i]>'9') {c=1; res[i]-=10;} else c=0;
    }
  return c;
}

void zpad(char *res, char *z)
{
  int l, i;
  for(i=0; i<127; i++) res[i] = '0';
  res[127] = 0;
  for(l=0; l<127; l++)
    {
      if (z[l] == 0) break;
    }
  for(i=0; i<l; i++)
    {
      res[127-l+i] = z[i];
    }
}

int main()
{
  in = stdin;
  mf = 2; zpad(fz[0], "1"); zpad(fz[1], "2"); zpad(ns, "0");
  while(add(fz[mf], fz[mf-2], fz[mf-1])==0)mf++;
  while(1)
    {
      fscanf(in, " %s %s ", i1, i2);
      zpad(z1, i1); zpad(z2, i2);
      if (strcmp(z2, ns) == 0) break;
      for(min=mf-1; min>=0; min--)
  {
    if (strcmp(z1, fz[min]) > 0) break;
  }
      for(max=0; max<mf; max++)
  {
    if (strcmp(z2, fz[max]) < 0) break;
  }
      printf("%d\n", max-min-1);
    }
  return 0;
  /* 1 2 3 5 8 13 21 34 55 89 */
}
