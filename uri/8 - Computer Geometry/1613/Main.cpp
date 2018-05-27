#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define EPS 1e-9
 
struct point {
    double x, y;
    point() { x = y = 0.0; }
    point( double _x, double _y ) : x(_x), y(_y) {}
    bool operator<( const point &p ) const {
        if( fabs( x - p.x ) < EPS )
            return y < p.y;
        return x < p.x;
    }
} epicentro, e[10005];

struct vec {
    double x, y;
    vec( double _x, double _y ) : x(_x), y(_y) {}
};
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }
double cross( vec a, vec b ) { return a.x*b.y - a.y*b.x; }
bool ccw1( point p, point q, point r ) { return cross( toVec( p, q ), toVec( p, r ) ) > 0.0; }
bool ccw2( point p, point q, point r ) { return cross( toVec( p, q ), toVec( p, r ) ) < 0.0; }

struct Parede {
    point pi, pf;
    Parede() {}
    Parede( double yi, double yf ) { pi.y = yi; pf.y = yf; }
    bool operator<( const Parede &p ) const { return pi.y < p.pi.y; }
} parede[10005];

int main() {
    int t, p, g, qe;
    double yi, yf;
    map< point, bool > mapa;

    scanf( "%d", &t );
    while( t-- ) {
        qe = 0;
        mapa.clear();
        scanf( "%lf%lf", &epicentro.x, &epicentro.y );
        scanf( "%d", &p );
        for( int i=0; i<p; i++ ) {
            scanf( "%lf%lf", &yi, &yf );
            parede[i] = Parede( yi, yf );
        }
        sort( parede, parede+p );
        scanf( "%d", &g );
        for( int i=0; i<g; i++ ) {
            scanf( "%lf%lf", &e[i].x, &e[i].y );
            if( !mapa.count( e[i] ) ) {
                mapa[ e[i] ] = 0;
                for( int j=0; j<p; j++ )
                    if( ccw1( epicentro, parede[j].pi, e[i] ) ) {
                        if( ccw2( epicentro, parede[j].pf, e[i] ) ) {
                            mapa[ e[i] ] = true;
                            qe++;
                            break;
                        }
                    } else
                        break;

            } else if( mapa[ e[i] ] )
                qe++;
        }
        printf( "%d\n", qe );
    }

    return 0;
}