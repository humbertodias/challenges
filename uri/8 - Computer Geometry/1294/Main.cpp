#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double l, w;

    while( scanf( "%lf%lf", &l, &w ) != EOF ) {
        double delta = sqrt( 16.0*( w + l )*( w + l ) - 48.0*w*l ),
               x = ( 4.0*( w + l ) - delta )/24.0;
               
        printf( "%.3lf 0.000 %.3lf\n", x, w > l ? l/2.0 : w/2.0 );
    }

    return 0;
}