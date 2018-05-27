#include <iostream>
#include <cstring>
#include <cstdio>
 
using namespace std;

int N, R, C, K;

int** batalha( int** t  ) {
    int** taux;

    taux = new int*[R];
    for( int i=0; i<R; i++ ) {
        taux[i] = new int[C];
        for( int j=0; j<C; j++ )
            taux[i][j] = t[i][j];
    }

    for( int i=0; i<R; i++ )
        for( int j=0; j<C; j++ ) {
            if( i-1 >= 0 && t[i-1][j] == ( t[i][j]+1 )%N )
                taux[i-1][j] = t[i][j];
            
            if( i+1 < R && t[i+1][j] == ( t[i][j]+1 )%N )
                taux[i+1][j] = t[i][j];
            
            if( j-1 >= 0 && t[i][j-1] == ( t[i][j]+1 )%N )
                taux[i][j-1] = t[i][j];
            
            if( j+1 < C && t[i][j+1] == ( t[i][j]+1 )%N )
                taux[i][j+1] = t[i][j];
        }

    return taux;
}

int main() {
    int** t;

    while( scanf( "%d%d%d%d", &N, &R, &C, &K ) && N ) {
        t = new int*[R];
        for( int i=0; i<R; i++ ) {
            t[i] = new int[C];
            for( int j=0; j<C; j++ )
                scanf( "%d", &t[i][j] );
        }
    
        for( int i=0; i<K; i++ )
            t = batalha( t );

        for( int i=0; i<R; i++ ) {
            bool espaco = false;
            for( int j=0; j<C; j++ )
                printf( "%s%d", ( espaco ? " " : "" ), t[i][j] ), espaco = true;
            printf( "\n" );
        }
    }

    return 0;
}
