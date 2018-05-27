#include <iostream>  
#include <cstdio>

using namespace std;
 
int main() {
    int n;
    double a, b, _b, t, s, v;

    while( scanf( "%d", &n ) && n ) {
        _b = s = v = 0.0;
        for( int i = 0; i < n; i++ ) {
            scanf( "%lf%lf", &a, &b );
            t = v/2.0;
            if( a - _b >= t ){
                s += v*t - t*t;
                v = 0.0;
            } else {
                t = a - _b;
                s += v*t - t*t;
                v = v - 2*t;
            }

            t = 10.0 - v;
            if( b - a >= t ) {
                s += v*t + t*t/2.0;
                v = 10.0;
                s += v*( b - a - t );
            } else {
                t = b - a;
                s += v*t + t*t/2.0;
                v = v + t;
            }
            _b = b;
        }
        printf( "%.2lf\n", s );
    }
 
    return 0;
}