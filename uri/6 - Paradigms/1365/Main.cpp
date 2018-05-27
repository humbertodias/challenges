#include <iostream>
#include <algorithm>

using namespace std;
int R, C, K;
int mat[301][300] = { 0 };

int min_area(int K)
{
   int diff;
   int area = R*C;

   for ( int i = 0; i < R; i++ )
      for ( int j = i+1; j <= R; j++ ) {
         int sum = 0, a = 0;
         for ( int b = 0; b < C; b++ ) {
            sum += mat[j][b] - mat[i][b];
            while ( diff = mat[j][a] - mat[i][a], sum - diff >= K )
               sum -= diff, ++a;
            if ( sum >= K )
               area = min(area, (j-i)*(b-a+1));
         }
      }
   return area;
}

int main()
{
   char ch;
   while ( cin >> R >> C >> K, R ) {
      for ( int i = 1; i <= R; i++ )
         for ( int j = 0; j < C; j++ ) {
            mat[i][j] = mat[i-1][j];
            if ( cin >> ch, ch == '.' )
               ++mat[i][j];
         }
      cout << min_area(K) << '\n';
   }
   return 0;
}