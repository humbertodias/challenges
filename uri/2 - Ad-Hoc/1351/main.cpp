#include <iostream>  
#include <vector>
#include <cstdio>

using namespace std;

#define INF 1e9

struct produto {
  int k;
  double p;
} p[100005];

int m, n, l[105];
double pd[105][100005];

double sp( int i, int j ) {
  if( i == m ) return 0;
  if( j == n ) return INF;
  if( pd[i][j] != 0 ) return pd[i][j];

  if( l[i] != p[j].k )
    pd[i][j] = sp( i, j+1 );
  else
    pd[i][j] = min( sp( i+1, j+1 ) + p[j].p, sp( i, j+1 ) );

  return pd[i][j];
}

int main() {
  while( scanf( "%d%d", &m, &n ) && m ) {
    for( int i=1; i<=m; i++ )
      scanf( "%d", &l[i] );
  
    for( int i=1; i<=n; i++ )
      scanf( "%d%lf", &p[i].k, &p[i].p );

    for( int i=0; i<=m; i++ )
      for( int j=0; j<=n; j++ ) {
        if( !i ) pd[i][j] = 0;
        else if( !j ) pd[i][j] = INF;
        else if( l[i] != p[j].k )
          pd[i][j] = pd[i][j-1];
        else
          pd[i][j] = min( pd[i-1][j-1] + p[j].p, pd[i][j-1] );
      }

    if( pd[m][n] == INF )
      printf( "Impossible\n" );
    else
      printf( "%.2lf\n", pd[m][n] );
  }

  return 0;
}