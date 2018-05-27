#include <iostream>  
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int n, r, q, x[1005], y[1005], g, t = 1;

  while( scanf( "%d%d", &n, &r ) && n ) {
    for( int i = 0; i < r; i++ )
      scanf( "%d%d", &x[i], &y[i] );
    printf( "Genome %d\n", t++ );
    scanf( "%d", &q );
    for( int i = 0; i < q; i++ ) {
      scanf( "%d", &g );
      for( int j = 0; j < r; j++ )
        if( x[j] <= g && g <= y[j] ) {
          int dif, meio = ( x[j] + y[j] )/2;
          if( ( x[j] + y[j] )&1 ) {
            if( g == meio ) g++;
            else if( g == meio + 1 ) g--;
            else if( g < meio )
              dif = g - x[j], g = y[j] - dif;
            else
              dif = y[j] - g, g = x[j] + dif;
          
          } else {
            if( g == meio ) continue;
            else if( g < meio )
              dif = g - x[j], g = y[j] - dif;
            else
              dif = y[j] - g, g = x[j] + dif;
          }
        }
      printf( "%d\n", g );
    }
  }

  return 0;
}