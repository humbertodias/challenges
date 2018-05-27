#include <iostream>
#include <map> // map
#include <vector> // vector
#include <algorithm> // search_n
#include <string> // string
#include <cstdio> // scanf
#include <cstring> // memset
#include <utility> // pair
#include <cmath>

using namespace std;

struct cilindro {
   int h, r;
   string cor;
   cilindro() {}
   bool operator<( const cilindro &c ) const { return r > c.r; }
} c[1005];

bool possivel( string c1, string c2 ){
    if( ( c1 == "VERMELHO" && c2 == "LARANJA" ) ||
      ( c1 == "LARANJA"  && c2 == "AZUL" ) ||
      ( c1 == "AZUL"     && c2 == "VERDE" ) ||
      ( c1 == "VERDE"    && c2 == "VERMELHO" ) )
      return false; 
    return true;
}

int main() {
   int n, h, sol[1005];

   while( cin >> n && n ) {
      for( int i = 0; i < n; i++ )
         cin >> c[i].h >> c[i].r >> c[i].cor;
      sort( c, c + n );
      memset( sol, 0, sizeof sol );
      h = 0;
      for( int i = 0; i < n; i++ ) {
         for( int j = i - 1; j >= 0; j-- )
                if( c[i].r < c[j].r && possivel( c[i].cor, c[j].cor ) )
                    sol[i] = max( sol[i], sol[j] );

            sol[i] += c[i].h;
            h = max( h, sol[i] );
      }
      cout << h << " centimetro(s)\n";
   }

   return 0;
}