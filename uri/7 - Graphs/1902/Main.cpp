#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define vi vector<int>

vi G[100005];
map<string,int> mapa;
int cor[100005], casamento = 0;

void dfs( int v ) {
   cor[ v ] = 1;

   for( int i=0; i<G[v].size(); i++ ) {
      int A = G[v][i];
      if( !cor[ A ] )
         dfs( A );
      else if( cor[A] != 2 )
         cor[A] = 2, casamento++;
   }
   cor[ v ] = 2;
}

int main() {
   int n = 1;
   string a1, ak;

   while( cin >> a1 >> ak ) {
      if( !mapa[ a1 ] ) mapa[ a1 ] = n++;
      if( !mapa[ ak ] ) mapa[ ak ] = n++;

      G[ mapa[ a1 ] ].push_back( mapa[ ak ] );
   }
   memset( cor, 0, sizeof cor );
   for( int i=1; i<n; i++ )
      if( !cor[i] )
         dfs( i );

   printf( "%d\n", casamento );

   return 0;
}