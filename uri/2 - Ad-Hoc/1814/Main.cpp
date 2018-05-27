  
#include <iostream>  
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct aresta {
  int v, d;
  aresta( int v, int d ) { this->v = v, this->d = d; }
  bool operator<( aresta a ) const { return d > a.d; }
};

priority_queue<aresta> fila;
bool d[105];

int main() {
  int n, m, qnt, inst = 1;
  string DNA[105];

  while( cin >> n >> m && n ) {
    qnt = 0;
    for( int i=0; i<n; i++ )
      cin >> DNA[i];
    
    memset( d, 0, sizeof d );
      fila.push( aresta( 0, 0 ) );
        while( !fila.empty() ) {
            aresta A = fila.top(); fila.pop();
            
          if( !d[ A.v ] ) {
            d[ A.v ] = true;
            qnt += A.d;

              for( int i=0; i<n; i++ )
                if( i != A.v ) {
                    aresta B( i, 0 );
                    for( int j=0; j<m; j++ )
                      if( DNA[ A.v ][j] != DNA[i][j] )
                        B.d++;

                    if( !d[ B.v ] )
                        fila.push( aresta( B ) );
                }
          }
        }
    cout << "Instancia " << inst++ << endl << qnt << endl << endl;
  }

  return 0;
}