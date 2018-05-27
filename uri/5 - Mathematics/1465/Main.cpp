#include <cstdio>
#include <cmath>

#define ll long long int

int main() {
  int m, n;
  ll a, b, r, i, r_aux, i_aux;

  scanf( "%d", &m );
  while( m-- ) {
    n = 0;
    scanf( "%lld %lld", &a, &b );
    r = a, i = b;
    while( ++n && i != 0 && sqrt( r*r + i*i ) < (ll)pow( 2, 30 ) ) {
      r_aux = r, i_aux = i;

      r = r_aux*a - i_aux*b;
      i = r_aux*b + i_aux*a;
    }
    if( !i ) printf( "%d\n", n );
    else printf( "TOO COMPLICATED\n" );
  }

  return 0;
}