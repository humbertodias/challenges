#include <cstring>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

vector<int> G[1005];
bool d[1005];
int qntB = 0;
char nota[1005];

void DFS( int v ) {
  d[v] = 1;
  if( nota[v] == 'B' )
    qntB++;

  for( int i=0; i<G[v].size(); i++ ) {
    int A = G[v][i];

    if( !d[A] )
      DFS( A );
  }
}

int main() {
  int n, m, a, b;
  bool possivel;

  while( scanf( "%d%d", &n, &m ) != EOF ) {
    for( int i=1; i<=n; i++ )
      scanf( " %c", &nota[i] ), G[i].clear();

    for( int i=0; i<m; i++ ) {
      scanf( "%d%d", &a, &b );
      G[a].push_back( b );
      G[b].push_back( a );
    }

    possivel = true;
    memset( d, 0, sizeof d );
    for( int i=1; i<=n && possivel; i++ ) {
      if( !d[i] )
        DFS( i );

      if( qntB&1 )
        possivel = false;
      
      qntB = 0;
    }
    cout << ( possivel ? "Y" : "N" ) << endl;
  }

  return 0;
}