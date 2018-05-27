#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int g, p, w, e[105], pc[105], t[105][1005];

  scanf( "%d", &g );
  for( int j = 1; j <= g; j++ ) {
    scanf( "%d%d", &p, &w );
    for( int i = 1; i <= p; i++ )
      scanf( "%d%d", &e[i], &pc[i] );
  
    for( int peso = 0; peso <= w; peso++ ) {
      t[0][peso] = 0;
      for( int i = 1; i <= p; i++ ) {
        if( pc[i] > peso )
          t[i][peso] = t[i-1][peso];
        else
          t[i][peso] = max( t[i-1][peso], t[i-1][ peso - pc[i] ] + e[i] );
      }
    }
    printf( "Galho %d:\nNumero total de enfeites: %d\n\n", j, t[p][w] );
  }

    return 0;
}