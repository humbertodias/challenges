  
#include <iostream>  
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

map<int,int> mapa;
map<int,int>::iterator it;

int main() {
  int t, n, tipo, q, soma;
  
  scanf( "%d", &t );
  while( t-- ) {
    soma = 0;
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ ) {
      scanf( "%d%d", &tipo, &q );
      if( !mapa[tipo] )
        mapa[tipo] = q;
      else if( 10 <= mapa[tipo] && mapa[tipo] <= 100 )
        mapa[tipo] = max( mapa[tipo], ( q <= 100 ? q : 0 ) );
      else if( 10 <= q && q <= 100 )
        mapa[tipo] = q;
      else
        mapa[tipo] = max( mapa[tipo], q );
    }
    for( it = mapa.begin(); it != mapa.end(); it++ )
      soma += it->second;
    printf( "%d\n", soma );
    mapa.clear();
  }

  return 0;
}