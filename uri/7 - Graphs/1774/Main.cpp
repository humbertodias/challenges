#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>


using namespace std;

struct aresta {
   int v, d;

   aresta( int v, int d ) {
      this->v = v;
      this->d = d;
   }
   bool operator<( aresta A ) const { return d > A.d; }
};

vector<aresta> G[65];
priority_queue<aresta> fila;
bool cor[65];

int main() {
   int r, c, v, w, p, custo;

   while( scanf( "%d%d", &c, &r ) != EOF ) {
      for( int i=1; i<=c; i++ ) G[i].clear();
      for( int i=0; i<r; i++ ) {
         scanf( "%d%d%d", &v, &w, &p );
         G[v].push_back( aresta( w, p ) );
         G[w].push_back( aresta( v, p ) );
      }
      
      memset( cor, false, sizeof cor );
      custo = 0;
      fila.push( aresta( 1, 0.0 ) );
      
      while( !fila.empty() ) {
         aresta A = fila.top(); fila.pop();

         if( !cor[ A.v ] ) {
            cor[ A.v ] = true;
            custo += A.d;
            
            for( int i=0; i<G[A.v].size(); i++ ) {
               aresta B = G[A.v][i];

               if( !cor[ B.v ] )
                  fila.push( B );
            }
         }
      }
      printf( "%d\n", custo );
   }

   return 0;
}