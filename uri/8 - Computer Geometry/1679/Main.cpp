#include <cstdio>
#include <cmath>

#define EPS 1e-9

int main() {
    double e = 335.0, cw = 4.19, ci = 2.09, mw, mi, m, tw, ti, Qw, Qi, QL, T;

    while( scanf( "%lf%lf%lf%lf", &mw, &mi, &tw, &ti ) && ( mw + mi ) > EPS ) {
        Qw = mw*cw*tw;
        Qi = mi*ci*(-ti);

        if( Qi > Qw ) {
            QL = mw*e;
            if( Qi > Qw + QL ) {
                Qi = -Qi;
                mi += mw;
                mw = 0.0;
                T = ( Qi + Qw + QL )/( mi*ci );

            } else {
                m = fabs( Qi - Qw )/e;
                mw -= m;
                mi += m;
                T = 0.0;
            }

        } else {
            QL = mi*e;
            if( Qi + QL > Qw ) {
                m = fabs( Qi - Qw )/e;
                mw += m;
                mi -= m;
                T = 0.0;

            } else {
                Qi = -Qi;
                mw += mi;
                mi = 0.0;
                T = ( Qw + Qi - QL )/( mw*cw );
            }
        }
        printf( "%.1lf g of ice and %.1lf g of water at %.1lf C\n", mi, mw, T );
    }

    return 0;
}