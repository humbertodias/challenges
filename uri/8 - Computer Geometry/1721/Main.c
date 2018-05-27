#include <stdio.h>
#include <math.h>
#include <string.h>

#define ER 6378.0
// #define M_PI 3.14159265358979323846

FILE *in;
char name[1000][64], c1[64], c2[64], c3[64];
int mn, i1, i2, i3;
double x[1999], y[1000];
double x3, x2, y3, y2, z3, z2, res;

int fcity(char *n)
{
  int i;
  for(i=0; i<mn; i++)
    {
      if (strcmp(name[i], n) == 0) return i;
    }
  return -1;
}

int main()
{
  in = stdin;
  mn = 0;
  while(1)
    {
      fscanf(in, " %s ", name[mn]);
      if (name[mn][0] == '#') break;
      fscanf(in, " %lf %lf ", &y[mn], &x[mn]);
      y[mn] = y[mn] * M_PI / 180.0;
      x[mn] = x[mn] * M_PI / 180.0;
      mn++;
    }
  while(1)
    {
      fscanf(in, " %s ", c1);
      if (c1[0] == '#') break;
      fscanf(in, " %s %s ", c2, c3);
      i1 = fcity(c1); i2 = fcity(c2); i3 = fcity(c3);
      if ((i1==-1) || (i2==-1) || (i3==-1))
    {
      printf("%s is ? km off %s/%s equidistance.\n", c3, c1, c2);
    }
      else
    {
      x3 = (cos(y[i1])*sin(x[i1])) - (cos(y[i2])*sin(x[i2]));
      y3 = (cos(y[i1])*cos(x[i1])) - (cos(y[i2])*cos(x[i2]));
      z3 = (sin(y[i1])) - (sin(y[i2]));
      x2 = (cos(y[i3])*sin(x[i3]));
      y2 = (cos(y[i3])*cos(x[i3]));
      z2 = (sin(y[i3]));
      res = (x3*x2 + y3*y2 + z3*z2) / (sqrt(x3*x3+y3*y3+z3*z3));
      if (res<0) res=-res;
      res = (M_PI / 2 - acos(res)) * ER;
      if ((y[i1]==y[i2]) && (x[i1]==x[i2])) res = 0.0;
      printf("%s is %d km off %s/%s equidistance.\n", c3, (int) floor(res+0.5),c1, c2);
    }
    }
  return 0;
}