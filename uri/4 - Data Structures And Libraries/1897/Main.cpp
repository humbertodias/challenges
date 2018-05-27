#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
 
using namespace std;

struct novo_N {
    int N, Q;
    novo_N() { Q = 0; }
    novo_N( int _N, int _Q ) : N(_N), Q(_Q) {}
};

int main() {
    int n, m;
    map<int,bool> mapa;
    queue<novo_N> fila;

    scanf( "%d%d", &n, &m );
    if( n != m )
        fila.push( novo_N( n, 0 ) );

    novo_N novo;
    while( !fila.empty() ) {
        novo = fila.front(); fila.pop();
        if( novo.N == m ) break;
        if( mapa[ novo.N ] ) continue;
        mapa[ novo.N ] = true;

        fila.push( novo_N( novo.N/2, novo.Q+1 ) );
        fila.push( novo_N( novo.N/3, novo.Q+1 ) );
        fila.push( novo_N( novo.N*2, novo.Q+1 ) );
        fila.push( novo_N( novo.N*3, novo.Q+1 ) );
        fila.push( novo_N( novo.N-7, novo.Q+1 ) );
        fila.push( novo_N( novo.N+7, novo.Q+1 ) );
    }
    printf( "%d\n", novo.Q );

    return 0;
}