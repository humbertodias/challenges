  
#include <cstdio>

using namespace std;

int main() {
  bool crescente = true;
  int n, k, h[1005], pico = 0;

  scanf( "%d%d", &n, &k );
  for( int i=0; i<n; i++ ) {
    scanf( "%d", &h[i] );
    if( crescente ) {
      if( i > 0 && h[i-1] > h[i] )
        pico++, crescente = false;
    } else {
      if( i > 0 && h[i-1] < h[i] )
        crescente = true;
    }
  }
  printf( "%s\n", pico == k ? "beautiful" : "ugly" );

  return 0;
}