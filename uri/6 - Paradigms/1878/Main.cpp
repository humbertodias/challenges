#include <iostream>
#include <map> // map
#include <vector> // vector
#include <algorithm> // search_n
#include <string> // string
#include <cstdio> // scanf
#include <cstring> // memset
#include <utility> // pair

using namespace std;

int main() {
   int n, m, c[5];
   bool pode;
   map<int,bool> mapa;

   while( scanf( "%d%d", &n, &m ) != EOF ) {
      for( int i=0; i<n; i++ )
         scanf( "%d", &c[i] );

      mapa.clear();
      pode = true;
      if( n == 1 ) {
         for( int t1=1; t1<=m && pode; t1++ ) {
            int colocacao = c[0]*t1;
            if( !mapa[ colocacao ] )
               mapa[ colocacao ] = true;
            else
               pode = false;
         }
      } else if( n == 2 ) {
         for( int t2=1; t2<=m && pode; t2++ )
            for( int t1=1; t1<=m && pode; t1++ ) {
               int colocacao = c[0]*t1  + c[1]*t2;
               if( !mapa[ colocacao ] )
                  mapa[ colocacao ] = true;
               else
                  pode = false;
            }
      } else {
         for( int t3=1; t3<=m && pode; t3++ )
            for( int t2=1; t2<=m && pode; t2++ )
               for( int t1=1; t1<=m && pode; t1++ ) {
                  int colocacao = c[0]*t1 + c[1]*t2 + c[2]*t3;
                  if( !mapa[ colocacao ] )
                     mapa[ colocacao ] = true;
                  else
                     pode = false;
               }
      }
      printf( "%s\n", pode ? "Lucky Denis!" : "Try again later, Denis..." );
   }

   return 0;
}