import java.util.*;
class Main{
    static final double EPS = 1e-9;

    public static void main(String []args) {
        double e = 335.0, cw = 4.19, ci = 2.09, mw=0, mi=0, m, tw, ti, Qw, Qi, QL, T;
        Scanner scanner = new Scanner(System.in);
        while( scanner.hasNext() ) {
            mw = scanner.nextDouble();
            mi = scanner.nextDouble();
            tw = scanner.nextDouble();
            ti = scanner.nextDouble();

            if ( ( mw + mi ) < EPS ) break;

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
                    m = Math.abs( Qi - Qw )/e;
                    mw -= m;
                    mi += m;
                    T = 0.0;
                }

            } else {
                QL = mi*e;
                if( Qi + QL > Qw ) {
                    m = Math.abs( Qi - Qw )/e;
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
            System.out.printf( "%.1f g of ice and %.1f g of water at %.1f C\n", mi, mw, T );
        }

    }

}