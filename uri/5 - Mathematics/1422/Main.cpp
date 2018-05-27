#include <iostream>
#include <cstring>
#include <cstdio>
 
using namespace std;

#define ll long long int
#define MOD 13371337
#define N 4

int** matMult( int **A, int **B ) {
    int **M; 
    M = new int*[N];
    for( int i = 0; i < N; i++ ) M[i] = new int[N];

    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++ ) {
            ll Mij = 0;
            for( int k = 0; k < N; k++ )
                Mij += (ll)A[i][k] * (ll)B[k][j];
            M[i][j] = Mij%MOD;
        }
    return M;
}
int** matPow( int **M, ll p ) {
    int **r;
    r = new int*[N];
    for( int i = 0; i < N; i++ ) r[i] = new int[N], r[i][i] = 1;

    while( p ) {
        if( p&1 ) r = matMult( r, M );
        M = matMult( M, M );
        p >>= 1;
    }
    return r;
}

int main() {
    int **M, **r;
    ll n, f[N], s[N], soma;

    while( scanf( "%lld", &n ) && n ) {
        f[3] = 0;
        for( int i = 3; i >= 0; i-- )
            scanf( "%lld", &f[i] ), s[i] = 0;

        M = new int*[N];
        for( int i = 0; i < N; i++ ) M[i] = new int[N];

        for( int i = 0; i < N; i++ ) M[i][0] = 1;
        for( int j = 0; j < N-1; j++ ) M[j][j+1] = 1;

        r = matPow( M, n-4 );
        soma = 0;
        for( int i = 0; i < N; i++ ) {
            for( int j = 0; j < N; j++ )
                s[i] += f[j] * (ll)r[j][i];
            s[i] %= MOD;
            soma += s[i];
        }
        printf( "%lld\n", soma%MOD );
    }

    return 0;
}
