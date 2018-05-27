#include <cstdio> // scanf
#include <cmath>
#include <cstdlib>

#define lli long long int

int main() {
   int n;
   lli ut, casa, casa_a;
   
   while( scanf( "%d", &n ) && n ) {
      ut = 0;
      for( int i=0; i<n; i++ ) {
         if( i > 0 ) casa_a = casa;
         scanf( "%lli", &casa );
         
         if( i > 0 ) casa += casa_a;
         ut += std::abs( casa );
      }
      printf( "%lli\n", ut );
   }

   return 0;
}