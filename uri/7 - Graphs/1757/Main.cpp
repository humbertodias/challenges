#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
 
int n, v;
bool G[105][105];
bool d[105];
 
void DFS( int v ) {
    d[v] = 1;
 
    for( int i=0; i<n; i++ )
        if( !d[i] && G[v][i] )
            DFS( i );
}
 
int main() {
    int t, a, b, qnt;
 
    scanf( "%d", &t );
    while( t-- ) {
        qnt = 0;
        scanf( "%d%d", &n, &v );
        for( int i=0; i<=n; i++ )
            for( int j=0; j<=n; j++ )
                if( i == j )
                    G[i][j] = 0;
                else
                    G[i][j] = 1;
                 
        for( int i=0; i<v; i++ ) {
            scanf( "%d%d", &a, &b );
            G[a][b] = 0;
            G[b][a] = 0;
        }
        memset( d, 0, sizeof d );
        for( int i=0; i<n; i++ )
            if( !d[i] )
                DFS( i ), qnt++;
 
        printf( "%d\n", ( !qnt ? qnt : qnt-1 ) );
    }
 
    return 0;
}