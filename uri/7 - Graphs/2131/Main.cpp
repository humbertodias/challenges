#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> G[105];
int cor[105];
bool possivel;

void dfs( int v, bool c ) {
  cor[v] = c;
  c = !c;

  for( int i=0, j; i<G[v].size() && possivel; i++ ) {
    j = G[v][i];
    if( cor[j] == -1 )
      dfs( j, c );
    else if( cor[j] != c )
      possivel = false;
  }
}

int main() {
  int n, m, u, v, t = 1;

  while( scanf( "%d%d", &n, &m ) != EOF ) {
    possivel = true;
    for( int i=0; i<n; i++ ) G[i].clear();
    memset( cor, -1, sizeof cor );

    for( int i=0; i<m; i++ ) {
      scanf( "%d%d", &u, &v );
      G[u-1].push_back( v-1 );
      G[v-1].push_back( u-1 );
    }
    for( int i=0; i<n && possivel; i++ )
      if( cor[i] == -1 ) dfs( i, 1 );

    printf( "Instancia %d\n%s\n\n", t++, ( possivel ? "sim" : "nao" ) );
  }

  return 0;
}