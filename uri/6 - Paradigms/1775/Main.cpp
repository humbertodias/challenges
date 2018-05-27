#include <cstdio>
#include <algorithm>
using namespace std;

int m[1005], np[1005][1005];

int p( int i, int f ) {
   if( i > f ) return 0;
   if( np[i][f] != -1 ) return np[i][f];

   np[i][f] = ( m[i] == m[f] ? p( i+1, f-1 ) : min( p( i+1, f ), p( i, f-1 ) ) ) + 1;

   return np[i][f];
}

int main() {
   int t, n;

   scanf( "%d", &t );
   for( int i=1; i<=t; i++ ) {
      scanf( "%d", &n );
      for( int j=1; j<=n; j++ ) {
         scanf( "%d", &m[j] );
         for( int k=j; k<=n; k++ )
                np[j][k] = -1;
      }
      printf( "Caso #%d: %d\n", i, p( 1, n ) );
   }

   return 0;
}