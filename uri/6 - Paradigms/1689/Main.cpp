#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LIM 1000000

int main() {
  int t, N, K, r, maiorI, i[LIM+5], radar[LIM+5];

  scanf( "%d", &t );
  while( t-- ) {
    scanf( "%d%d", &N, &K );
    memset( i, 0, sizeof i );
    memset( radar, 0, sizeof radar );

    for( int j=0; j<N; j++ )
      scanf( "%d", &i[j] );
    for( int j=0; j<N; j++ ) {
      scanf( "%d", &r );
      radar[ i[j] ] = max( r, radar[ i[j] ] );
    }
    maiorI = i[ N-1 ];
      for( int j=maiorI; j>=0; j-- )
            radar[j] = j+K <= maiorI ? max( radar[j] + radar[j+K], radar[j+1] ) : max( radar[j], radar[j+1] );
  
        printf( "%d\n", radar[0] );
  }

  return 0;
}