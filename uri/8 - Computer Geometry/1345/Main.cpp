#include <cstdio>
#include <cmath>

int main ()
{
   int x1, y1, x2, y2, n, m1, m2, d, dis, x, y;
   while (scanf (" %d %d %d %d", &x1, &y1, &x2, &y2)) {
      if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) break;
      scanf (" %d", &n);
      m1 = (x1 + x2) / 2;
      m2 = (y1 + y2) / 2;
      dis = 20000;
      while (n--) {
         scanf (" %d %d", &x, &y);
         d = (x-m1) * (x-m1) + (y-m2) * (y-m2);
         if (d < 0) d = d * (-1);
         d = sqrt(d);
         if (d <= dis ) {
            dis = d;
            x2 = x;
            y2 = y;
         }
      }
      printf ("%d %d\n", x2, y2);
   }
   return 0;
}