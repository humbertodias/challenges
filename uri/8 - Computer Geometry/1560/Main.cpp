#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct ponto {
    int x, y;
    bool operator<( const ponto &A ) const { return x < A.x; }
} p[205];

int area( ponto a, ponto b, ponto c ) {
    return abs( ( a.x*b.y + a.y*c.x + b.x*c.y ) - ( b.y*c.x + a.y*b.x + a.x*c.y ) );
}

int main() {
    int n, m, energia, tb;

    while( scanf( "%d%d", &n, &m ) != EOF ) {
        for( int i=0; i<n+m; i++ )
            scanf( "%d%d", &p[i].x, &p[i].y );

        sort( p, p+n );
        sort( p+n, p+n+m );
        energia = 0;
        for( int i=0; i<n; i++ )
            for( int j=i+1; j<n; j++ )
                for( int k=j+1; k<n; k++ ) {
                    tb = 0;
                    int ATpreto = area( p[i], p[j], p[k] );

                    for( int q=n; q<n+m; q++ ) {
                        if( p[q] < p[i] || p[k] < p[q] ) continue;
                        int a1 = area( p[i], p[j], p[q] );
                        int a2 = area( p[j], p[k], p[q] );
                        int a3 = area( p[k], p[i], p[q] );

                        if( a1 + a2 + a3 == ATpreto )
                            tb++;
                    }
                    energia += tb*tb;
                }

        printf( "%d\n", energia );
    }

    return 0;
}