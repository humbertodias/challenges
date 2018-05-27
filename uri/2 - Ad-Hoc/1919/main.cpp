  
#include <iostream>  
#include <vector>
#include <cstdio>

using namespace std;
 
int main(){
    int K, T, vetor[15], i, j, k, l, m;
    vetor[0] = 0;
    vetor[1] = 11111;
    vetor[2] = 22222;
    vetor[3] = 33333;
    vetor[4] = 44444;
    vetor[5] = 55555;
    vetor[6] = 66666;
    vetor[7] = 77777;
    vetor[8] = 88888;
    vetor[9] = 99999;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &K );
        bool existe = false;
        if( K%24 == 0 ) {
            K /= 24;
            for( i = 0; i <= 9; i++ )
                for( j = i+1; j <= 9; j++ )
                    for( k = j+1; k <= 9; k++ )
                        for( l = k+1; l <= 9; l++ )
                            for( m = l+1; m <= 9; m++ )
                                if( vetor[i] + vetor[j] + vetor[k] + vetor[l] + vetor[m] == K )
                                    printf( "{%d,%d,%d,%d,%d}\n", i, j, k, l, m ), existe = true;
        }
        if( !existe ) printf( "impossivel\n" );
        printf( "\n" );
    }
    return 0;
}