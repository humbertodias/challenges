#include <cstring>
#include <cstdio>
 
#define MOD 303700049
#define ll long long int
 
ll N, K;
 
int** matMult( int **A, int **B ) {
    int **M; 
    M = new int*[N+1];
    for( int i = 0; i < N+1; i++ ) M[i] = new int[N+1];
 
    for( int i = 0; i < N+1; i++ )
        for( int j = 0; j < N+1; j++ ) {
            ll Mij = 0;
            for( int k = 0; k < N+1; k++ )
                Mij += (ll)A[i][k] * (ll)B[k][j];
            M[i][j] = Mij%MOD;
        }
    return M;
}

int** matPow( int **M, ll p ) {
    int **r;
    r = new int*[N+1];
    for( int i = 0; i < N+1; i++ ) r[i] = new int[N+1], r[i][i] = 1;
 
    while( p ) {
        if( p&1 ) r = matMult( r, M );
        M = matMult( M, M );
        p >>= 1;
    }
    return r;
}
 
int main() {
    int **M, **r;
    ll fi, f[105], fn, soma;
 
    while( scanf( "%lld%lld", &N, &K ) != EOF ) {
        f[N] = 0;
        for( int i = N-1; i >= 0; i-- )
            scanf( "%lld", &fi ), f[i] = fi%MOD, f[N] += f[i];
 
        M = new int*[N+1];
        for( int i = 0; i < N+1; i++ ) M[i] = new int[N+1];
             
        for( int i = 0; i < N; i++ ) M[i][0] = i+1;
        for( int j = 0; j < N-1; j++ ) M[j][j+1] = 1;
        M[0][N] = 1;
        M[N][N] = 1;
 
        r = matPow( M, K-N );
 
        f[N] = ( f[N] - f[0] )%MOD;
        fn = 0, soma = 0;
        for( int i = 0; i <= N; i++ ) {
            fn += f[i] * (ll)r[i][0];
            soma += f[i] * (ll)r[i][N];
        }
        printf( "%lld %lld\n", fn%MOD, ( soma%MOD + fn%MOD )%MOD );
    }
 
    return 0;
}
