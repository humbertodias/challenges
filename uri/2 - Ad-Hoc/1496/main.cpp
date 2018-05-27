#include <iostream>  
#include <vector>
#include <cstdio>

using namespace std;
 
#define MAXN 100005
#define vi vector<int>
 
class SegmentTree {
    private:
        vi st, A;
        int n;
        int left( int p ) { return p << 1; }
        int right( int p ) { return ( p << 1 ) + 1; }
 
        void build( int p, int L, int R ) {
            if( L == R ) st[p] = L;
            else {
                build( left(p), L, ( L + R )/2 );
                build( right(p), ( L + R )/2 + 1, R );
                int p1 = st[ left(p) ], p2 = st[ right(p) ];
                st[p] = ( A[p1] <= A[p2] ) ? p1 : p2;
            }
        }
        int rmq( int p, int L, int R, int i, int j ) {
            if( i > R || j < L ) return -1;
            if( L >= i && R <= j ) return st[p];
 
            int p1 = rmq( left(p), L, ( L + R )/2, i, j );
            int p2 = rmq( right(p), ( L + R )/2 + 1, R, i, j );
 
            if( p1 == -1 ) return p2;
            if( p2 == -1 ) return p1;
             
            return ( A[p1] <= A[p2] ) ? p1 : p2;
        }
 
    public:
        SegmentTree( const vi &_A ) {
            A = _A; n = (int)A.size();
            st.assign( 4*n, 0 );
            build( 1, 0, n-1 );
        }
        int rmq( int i, int j ) { return rmq( 1, 0, n-1, i, j ); }
};
 
int l[MAXN], r[MAXN];
vi A;
 
int main() {
    int n;
 
    while( scanf( "%d", &n ) != EOF ) {
        A.assign( n, 0 );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &A[i] );
        SegmentTree st( A );
 
        l[0] = -1;
        for( int i = 1, aux; i < n; i++ ) {
            aux = i-1;
            while( aux != -1 && A[aux] <= A[i] ) aux = l[aux];
            l[i] = aux;
        }
        r[n-1] = -1;
        for( int i = n-2, aux; i >= 0; i-- ) {
            aux = i+1;
            while( aux != -1 && A[aux] <= A[i] ) aux = r[aux];
            r[i] = aux;
        }
 
        bool espaco = false;
        for( int i = 0; i < n; i++ )
            if( l[i] == -1 && r[i] == -1 ) {
                if( A[i] >= 150000 )
                    printf( "%s%d", ( espaco ? " " : "" ), i+1 ), espaco = true;
             
            } else if( l[i] == -1 ) {
                if( A[i] - A[ st.rmq( i, r[i] ) ] >= 150000 )
                    printf( "%s%d", ( espaco ? " " : "" ), i+1 ), espaco = true;
 
            } else if( r[i] == -1 ) {
                if( A[i] - A[ st.rmq( l[i], i ) ] >= 150000 )
                    printf( "%s%d", ( espaco ? " " : "" ), i+1 ), espaco = true;
             
            } else {
                if( A[i] - max( A[ st.rmq( l[i], i ) ], A[ st.rmq( i, r[i] ) ] ) >= 150000 )
                    printf( "%s%d", ( espaco ? " " : "" ), i+1 ), espaco = true;
                 
            }

        printf( "\n" );
    } 
 
    return 0;
}