#include <iostream>  
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int j, r, v, jogador[505], maior = 0;
  memset( jogador, 0, sizeof jogador );

  scanf( "%d%d", &j, &r );
  for( int i = 0; i < r; i++ )
    for( int k = 1; k <= j; k++ ) {
      scanf( "%d", &v );
      jogador[k] += v;
      maior = max( maior, jogador[k] );
    }

  for( int i = j; i >= 1; i-- )
    if( maior == jogador[i] ) {
      printf( "%d\n", i );
      break;
    }

  return 0;
}