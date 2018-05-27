#include <iostream>  
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int

struct ponto {
  ll x, y;
} p[1005];

ll dist( ponto a, ponto b ) {
  return ( a.x - b.x )*( a.x - b.x ) + ( a.y - b.y )*( a.y - b.y );
}

int main() {
  int n;
  ll k, ti, d[1005];

  while( scanf( "%d", &n ) && n ) {
    for( int i=0; i<n; i++ )
      scanf( "%lld%lld", &p[i].x, &p[i].y );

    ti = 0;
    for( int i=0; i<n; i++ ) {
      for( int j=0; j<n; j++ )
        d[j] = dist( p[i], p[j] );
      sort( d, d+n );

      k = 1;
      for( int j=1; j<n; j++ )
        if( d[j] == d[j-1] )
          k++;
        else {
          if( k >= 2 )
            ti += k*( k - 1 )/2;
          k = 1;
        }

      if( k >= 2 )
        ti += k*( k - 1 )/2;
    }
    printf( "%lld\n", ti );
  }

  return 0;
}