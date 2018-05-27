#include <iostream>
#include <string> // string
#include <cstdio> // scanf
#include <cstring> // memset

using namespace std;

int main() {
   int m, count, maior, mapa[256];
   string texto;

   while( cin >> m && m ) {
      memset( mapa, 0, sizeof mapa );
      count = maior = 0;
      cin.ignore();
      getline( cin, texto );

      for( int i=0, j=0; i<texto.size(); i++ ) {
         mapa[ (int)texto[i] ]++;
         if( mapa[ (int)texto[i]] == 1 ) {
            count++;
            while( count > m ) {
               if( --mapa[ (int)texto[j]] == 0 )
                  count--;
               j++;
            }
         }
         maior = max( maior, i - j + 1 );
      }
      cout << maior << endl;
   }

   return 0;
}