#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;
 
#define INF 1e9

vector<int> G[1005];
int d[1005], at[1005];
 
int main() {
    int teste, n, m, f, u, v, p, a, c, q, k, h, mv;
 
    scanf( "%d", &teste );
    for( int t=1; t<=teste; t++ ) {
        scanf( "%d%d%d", &n, &m, &f );
        for( int i=1; i<=n; i++ ) G[i].clear();
        for( int i=0; i<m; i++ ) {
            scanf( "%d%d", &u, &v );
            G[u].push_back( v );
            G[v].push_back( u );
        }
        
        memset( at, 0, sizeof at );
        scanf( "%d", &p );
        while( p-- ) {
            scanf( "%d%d%d", &v, &a, &c );
            
            memset( d, -1, sizeof d );
            d[v] = 0;
            queue<int> fila;
            fila.push( v );
            while( !fila.empty() ) {
                int A = fila.front(); fila.pop();
                if( A == f ) continue;
                at[A] += a;

                if( d[A] + 1 <= c )
                    for( int j=0; j<G[A].size(); j++ ) {
                        int B = G[A][j];

                        if( d[B] == -1 ) {
                            d[B] = d[A] + 1;
                            fila.push( B );
                        }
                    }
            }
        }
 
        for( int i=1; i<=n; i++ ) d[i] = INF;
        d[f] = at[f] = 0;
        priority_queue<int> fila;
        fila.push( f );
        while( !fila.empty() ) {
            int A = fila.top(); fila.pop();

            for( int i=0; i<G[A].size(); i++ ) {
                int B = G[A][i];

                if( d[B] > d[A] + at[B] ) {
                    d[B] = d[A] + at[B];
                    fila.push( B );
                }
            }
        }

        mv = 0;
        scanf( "%d", &q );
        while( q-- ) {
            scanf( "%d%d", &k, &h );
            mv += ( h > d[k] );
        }
        printf( "Caso #%d: %d\n", t, mv );
    }
 
    return 0;
}