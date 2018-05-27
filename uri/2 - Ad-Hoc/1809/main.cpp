#include <iostream>  
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct aresta {
  int v;
  double d;

  aresta( int v, double d ) { this->v = v; this->d = d; }
  bool operator<( aresta a ) const { return d > a.d; }
};

vector<aresta> G[105];
priority_queue<aresta> fila;
bool d[105];

int main() {
  int m, n, x, y, t = 1;
  bool espaco = false;
  double p;

  while( scanf( "%d%d", &n, &m ) && n ) {
    for( int i=1; i<=n; i++ ) G[i].clear();
    for( int i=0; i<m; i++ ) {
          scanf( "%d%d%lf", &x, &y, &p );
          G[x].push_back( aresta( y, p ) );
        G[y].push_back( aresta( x, p ) );
      }
      p = 1.0;
      memset( d, 0, sizeof d );
      fila.push( aresta( 1, 0.0 ) );
        while( !fila.empty() ) {
            aresta A = fila.top(); fila.pop();
            
          if( !d[ A.v ] ) {
            d[ A.v ] = true;
            p *= ( 1.0 - A.d );

              for( int j=0; j<G[ A.v ].size(); j++ ) {
                  aresta B = G[ A.v ][j];

                  if( !d[ B.v ] )
                      fila.push( aresta( B ) );
              }
          }
        }
        printf( "%sCenario %d, probabilidade de interceptacao = %.3lf\n", ( espaco ? "\n" : "" ), t++, 1.0 - p ), espaco = true;
  }

  return 0;
}