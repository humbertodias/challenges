#include <iostream>
#include <cstdio>

using namespace std;

#define llu long long unsigned
#define MOD 1000000007

int n;
int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a%b ); }

int** mult( int **A, int **B ) {
   int **M;
   M = new int*[n*n+1];

   for( int i = 1; i <= n*n; i++ ) {
      M[i] = new int[n*n+1];
      for( int j = 1; j <= n*n; j++ ) {
         llu mij = 0;
         for( int k = 1; k <= n*n; k++ )
            mij += (llu)A[i][k]*(llu)B[k][j];
         M[i][j] = mij%MOD;
      }
   }
   return M;
}

int n_padrao( int **M ) {
   llu padroes = 0;
   for( int i = 1; i <= n*n; i++ )
      for( int j = 1; j <= n*n; j++ )
         padroes += (llu)M[i][j];

   return padroes%MOD;
}

int main() {
   int **A, **answer;
   llu p;

   while( scanf( "%d%llu", &n, &p ) != EOF ) {
      A = new int*[n*n+1];
      answer = new int*[n*n+1];
      for( int i = 1; i <= n*n; i++ ) {
         A[i] = new int[n*n+1];
         answer[i] = new int[n*n+1];
         for( int j = 1; j <= n*n; j++ )
            A[i][j] = answer[i][j] = 0;
         answer[i][i] = 1;
      }

      for( int i = 1; i <= n; i++ )
         for( int j = 1; j <= n; j++ )
            for( int ii = 1; ii <= n; ii++ )
               for( int jj = 1; jj <= n; jj++ )
                  if( i == ii && j == jj )
                     continue;
                  else if( i == ii && abs( jj - j ) == 1 )
                     A[ (i-1)*n + j ][ (ii-1)*n + jj ] = 1;
                  else if( j == jj && abs( ii - i ) == 1 )
                     A[ (i-1)*n + j ][ (ii-1)*n + jj ] = 1;
                  else if( gcd( abs( ii - i ), abs( jj - j ) ) == 1 )
                     A[ (i-1)*n + j ][ (ii-1)*n + jj ] = 1;

      while( p ) {
         if( p&1 ) answer = mult( answer, A );
         A = mult( A, A );
         p >>= 1;
      }
      printf( "%d\n", n_padrao( answer ) );
   }

   return 0;
}