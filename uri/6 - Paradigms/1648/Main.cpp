// Problem   Help Bob
// Algorithm exponential dynamic programming
// Runtime   O(m*2^m)

#include <iostream>
#include <fstream>
using namespace std;
const int M = 16;
double d[M][M], p[M], a[M], dp[1<<M];
double cost[1<<M][M];
int main()
{
   int m;
   while (cin >> m)
   {
      if (m == 0)
         break;
      for (int i=0; i<m; i++)
         for (int j=0; j<m; j++)
            d[i][j] = 1.0;
      for (int i=0; i<m; i++)
      {
         int n;
         cin >> p[i] >> a[i] >> n;
         for (int j=0; j<n; j++)
         {
            int x, y;
            cin >> x >> y;
            d[i][x-1] *= (100 - y) * 0.01;
         }
      }
      double res = 1e20;
      int k = 1 << m;
      for (int i=0; i<k; i++)
         dp[i] = res;
      dp[0] = 0.0;
      for (int i=0; i<m; i++)
         cost[0][i] = p[i];
      for (int mask=0; mask<k; mask++)
      {
         double area = 0.0;
         for (int i=0; i<m; i++)
            if (mask & (1 << i))
            {
               for (int j=0; j<m; j++)
                  cost[mask][j] = cost[mask ^ (1 << i)][j] * d[i][j];
               break;
            }
         for (int i=0; i<m; i++)
            if (mask & (1 << i))
               area += a[i];
            else if (dp[mask] + cost[mask][i] < dp[mask | (1 << i)])
                  dp[mask | (1 << i)] = dp[mask] + cost[mask][i];
         if (mask)
         {
            double tmp = dp[mask] / area;
            if (tmp < res)
               res = tmp;
         }
      }
      cout.setf(ios::fixed);
      cout.precision(4);
      cout << res << endl;
   }
   return 0;
}