#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define INF (int)1e9
#define point pair<int,int>
#define x first
#define y second

vector<point> p;
point menor, maior;

int main() {
    int n, X, Y, q = 0;

    scanf( "%d", &n );
    for( int i = 0; i < n; i++ ) {
        scanf( "%d%d", &X, &Y );
        p.push_back( point( X, Y ) );
    }
    sort( p.begin(), p.end() );
    for( int i = 0; i < n-1; i++ ) {
        menor.x = -INF;
        menor.y = -INF;
        maior.x = INF;
        maior.y = INF;
        for( int j = i+1; j < n; j++ ) {
            if( p[j].y == p[i].y ) break;

            if( p[j].y < p[i].y ) {
                if( p[j].x == menor.x )
                    menor.y = max( menor.y, p[j].y );
                else if( p[j].y > menor.y )
                    q++, menor = p[j];
            
            } else {
                if( p[j].x == maior.x )
                    maior.y = min( maior.y, p[j].y );
                else if( p[j].y < maior.y )
                    q++, maior = p[j];
            }
        }
    }
    printf( "%d\n", q );

    return 0;
}