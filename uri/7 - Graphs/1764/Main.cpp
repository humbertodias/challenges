#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
 
using namespace std;

struct aresta {
    int v, d;

    aresta( int v, int d ) {
        this->v = v;
        this->d = d;
    }
    bool operator<( aresta A ) const { return d > A.d; }
};

vector<aresta> G[40005];
priority_queue<aresta> fila;
bool cor[40005];

int main() {
    int m, n, x, y, z, d;

    while( scanf( "%d%d", &m, &n ) && m ) {
        for( int i=0; i<=m; i++ ) G[i].clear();
        for( int i=0; i<n; i++ ) {
            scanf( "%d%d%d", &x, &y, &z );
            G[x].push_back( aresta( y, z ) );
            G[y].push_back( aresta( x, z ) );
        }
        
        memset( cor, false, sizeof cor );
        d = 0;
        fila.push( aresta( 0, 0.0 ) );
        
        while( !fila.empty() ) {
            aresta A = fila.top(); fila.pop();

            if( !cor[ A.v ] ) {
                cor[ A.v ] = true;
                d += A.d;
                
                for( int i=0; i<G[A.v].size(); i++ ) {
                    aresta B = G[A.v][i];

                    if( !cor[ B.v ] )
                        fila.push( B );
                }
            }
        }
        printf( "%d\n", d );
    }

    return 0;
}
