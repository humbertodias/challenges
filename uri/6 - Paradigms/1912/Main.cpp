#include <iostream>
#include <map> // map
#include <vector> // vector
#include <algorithm> // search_n
#include <string> // string
#include <cstdio> // scanf
#include <cstring> // memset
#include <utility> // pair

using namespace std;
 
struct tira {
    int c, l;
    tira() {}
    tira( int _c, int _l ) : c(_c), l(_l) {}
    bool operator<( const tira &t ) const { return c > t.c; }
} t[100005];
 
int main() {
    int n, a;
 
    while( scanf( "%d%d", &n, &a ) && n ) {
        for( int i = 0; i < n; i++ ) {
            t[i].l = 1;
            scanf( "%d", &t[i].c );
        }
        sort( t, t+n );
        t[n].c = 0, t[n].l = 1;
        for( int i = 0; i < n; i++ ) {
            if( t[i].c == t[i+1].c )
                t[i+1].l += t[i].l;
                 
            else {
                int aux = ( t[i].c - t[i+1].c )*t[i].l;
                if( a > aux ) {
                    if( i == n-1 ) {
                        printf( "-.-\n" );
                        break;
                    }
                    a -= aux;
                    t[i+1].l += t[i].l;
                     
                } else {
                    if( i == n-1 && a == aux ) {
                        printf( ":D\n" );
                        break;
                    }
                    printf( "%.4lf\n", (double)t[i].c - (double)a/t[i].l );
                    break;
                }
            }
        }
    }
 
    return 0;
}