#include <iostream>  
#include <cmath>
#include <cstdio>

using namespace std;

#define DEG_to_RAD( t ) t*M_PI/180.0
#define EPS 1e-9
#define ll long long int
#define ld long double

struct point {
    ld x, y;
    point() { x = y = 0.0; }
    point( ld _x, ld _y ) : x(_x), y(_y) {}
} p;

point rotate( point &p, ld theta ) {
    ld rad = DEG_to_RAD( theta );
    return point( p.x*cos( rad ) - p.y*sin( rad ), p.x*sin( rad ) + p.y*cos( rad ) );
}

int main() {
  int t;
  ll n;
  ld l, a;

  scanf( "%d", &t );
  while( t-- ) {
    point p;
    scanf( "%Lf%Lf%lld", &a, &l, &n );
    if( a < EPS || fabs( a - 360.0 ) < EPS )
      printf( "%.2Lf 0.00\n", (ld)l*n );
    else {
      ll padrao = 1;
      p.x += l;

      while( !( fabs( p.x ) < EPS && fabs( p.y ) < EPS ) && padrao < n ) {
        p = rotate( p, a );
        p.x += l;
        padrao++;
      }
      if( padrao < n ) {
        padrao = n%padrao;
        while( padrao-- ) {
          p = rotate( p, a );
          p.x += l;
        }
      }
      if( fabs( p.x ) < EPS ) p.x = fabs( p.x );
      if( fabs( p.y ) < EPS ) p.y = fabs( p.y );
      printf( "%.2Lf %.2Lf\n", p.x, p.y );
    }
  }

  return 0;
}