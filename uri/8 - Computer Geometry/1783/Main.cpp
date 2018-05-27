#include <cstdio>

using namespace std;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point( double _x, double _y ) : x(_x), y(_y) {}
} pa[3], pb[3];

int main() {
    int t;
    double x, y;

    scanf( "%d", &t );
    for( int c=1; c<=t; c++ ) {
        for( int i=1; i<=2; i++ )
            scanf( "%lf%lf%lf%lf", &pa[i].x, &pa[i].y, &pb[i].x, &pb[i].y );

        double ka = ( pa[2].x*pa[2].x - pa[1].x*pa[1].x + pa[2].y*pa[2].y - pa[1].y*pa[1].y ),
               kb = ( pb[2].x*pb[2].x - pb[1].x*pb[1].x + pb[2].y*pb[2].y - pb[1].y*pb[1].y ),
               kax = 2.0*( pa[1].x - pa[2].x ),
               kbx = 2.0*( pb[1].x - pb[2].x ),
               kay = 2.0*( pa[2].y - pa[1].y ),
               kby = 2.0*( pb[2].y - pb[1].y );

        x = ( ka*kby - kb*kay )/( kbx*kay - kax*kby );
        
        if( kay != 0 )
            y = ( ka + x*kax )/kay;
        else
            y = ( kb + x*kbx )/kby;

        if(x == -0) x = 0;
        if(y == -0) y = 0;
        
        printf( "Caso #%d: %.2lf %.2lf\n", c, x, y );
    }

    return 0;
}