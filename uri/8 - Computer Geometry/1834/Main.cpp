#include <cstdio>
#include <cmath>

using namespace std;

#define ll long long int

struct point {
    ll h;
    double x, y;
    point() { x = y = h = 0; }
    point( double _x, double _y, ll _h ) : x(_x), y(_y), h(_h) {}
} p[10005];

struct vec {
    double x, y;
    vec( double _x, double _y ) : x(_x), y(_y) {}
};

vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }
double dist( point a, point b ) { return hypot( a.x - b.x, a.y - b.y ); }
double cross( vec a, vec b ) { return a.x*b.y - a.y*b.x; }

int main() {
    ll n, soh, sop, slh, slp;
    point a, b;

    scanf( "%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y );
    soh = sop = slh = slp = 0;

    scanf( "%lld", &n );
    for( int i=0; i<n; i++ )
        scanf( "%lf%lf%lld", &p[i].x, &p[i].y, &p[i].h );

    vec ab = toVec( a, b );
    for( int i=0; i<n; i++ ) {
        vec ap = toVec( a, p[i] );
        double pv = cross( ab, ap );
        if( pv == 0.0 ) continue;
        if( pv > 0 )
            soh += p[i].h, sop++;
        else
            slh += p[i].h, slp++;
    }
    printf( "Relatorio Vogon #35987-2\n" );
    printf( "Distancia entre referencias: %.2lf anos-luz\n", dist( a, b ) );
    printf( "Setor Oeste:\n- %lld planeta(s)\n- %lld bilhao(oes) de habitante(s)\n", sop, soh );
    printf( "Setor Leste:\n- %lld planeta(s)\n- %lld bilhao(oes) de habitante(s)\n", slp, slh );
    printf( "Casualidades: %lld planeta(s)\n", n - sop - slp );

    return 0;
}