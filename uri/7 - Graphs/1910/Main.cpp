#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring> // memset

using namespace std;

#define MAXN 1000000
#define valid(a) a >= 1 && a <= 1e5
 
int main(){
    int O, D, K, canaisPassados[MAXN+5], aux;
    queue<int> fila;
    while( scanf( " %d %d %d", &O, &D, &K ) && O ) {
        while( !fila.empty() ) fila.pop();
        memset( canaisPassados, 0, sizeof canaisPassados );
        canaisPassados[O] = 1;
        for( int i = 0; i < K; i++ ) {
            scanf( "%d", &aux );
            if( valid( aux ) )
                canaisPassados[aux] = -1;
        }       
        fila.push( O );
        while( !fila.empty() ) {
            int aux = fila.front(); fila.pop();
            if( aux == D ) break;
            int a = aux+1;
            if( valid(a) && canaisPassados[a] == 0 ){
                canaisPassados[a] = canaisPassados[aux] + 1;
                fila.push(a);
            }
            a = aux-1;
            if( valid(a) && canaisPassados[a] == 0 ){
                canaisPassados[a] = canaisPassados[aux] + 1;
                fila.push(a);
            }
            a = aux*2;
            if( valid(a) && canaisPassados[a] == 0 ){
                canaisPassados[a] = canaisPassados[aux] + 1;
                fila.push(a);
            }
            a = aux*3;
            if( valid(a) && canaisPassados[a] == 0 ){
                canaisPassados[a] = canaisPassados[aux] + 1;
                fila.push(a);
            }
            a = aux/2;
            if( aux%2 == 0 && valid(a) && canaisPassados[a] == 0 ){
                canaisPassados[a] = canaisPassados[aux] + 1;
                fila.push(a);
            }
        }
        if( canaisPassados[D] <= 0 ) printf( "-1\n" );
        else printf( "%d\n", canaisPassados[D]-1 );       
    }
    return 0;
}