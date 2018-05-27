#include <iostream>
#include <cstring>
#include <cstdio>
 
using namespace std;

#define ll long long int

int c;

int** matMult( int **A, int **B ) {
    int **M;
    M = new int*[2];

    for( int i = 0; i < 2; i++ ) {
        M[i] = new int[2];
        for( int j = 0; j < 2; j++ ) {
            ll Mij = 0;
            for( int k = 0; k < 2; k++ )
                Mij += (ll)A[i][k] * (ll)B[k][j];
            M[i][j] = Mij%c;
        }
    }
    return M;
}

int** matPow( int **M, int n ) {
    int **r;
    r = new int*[2];
    for( int i = 0; i < 2; i++ ) r[i] = new int[2], r[i][i] = 1;
    while( n ) {
        if( n&1 ) r = matMult( r, M );
        M = matMult( M, M );
        n >>= 1;
    }
    return r;
}

int f[20000000];

int main() {
    int n, m;
    int **fib, **fn;

    fib = new int*[2];
    for( int i = 0; i < 2; i++ ) fib[i] = new int[2];
    fib[0][0] = fib[0][1] = fib[1][0] = 1;
    fib[1][1] = 0;
    
    f[1] = f[2] = 1;

    while( scanf( "%d%d", &n, &m ) != EOF ) {
        for( c = 3; ; c++ ) {
            f[c] = ( f[c-1] + f[c-2] )%m;
            if( f[c] == f[c-1] && f[c] == 1 ) {
                c -= 2;
                f[0] = f[c];
                break;
            }
        }
        fn = matPow( fib, n );
        printf( "%d\n", f[ fn[0][1]%c ] );
    }
    return 0;
}
