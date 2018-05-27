#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main() {

   const long long max1 = 200;
   for(long long a1 = 1; a1 < max1; ++a1) {
      long long max = 2000/3;
      for(long long a2 = a1; a2 < max; ++a2) {
         long long max3 = 2000/2;
         for(long long a3 = a2; a3 < max3; ++a3) {
            if(a1 * a2 * a3 <= 1000000LL)
               continue;
            long long nom = 1000000LL * (a1 + a2 + a3);
            long long den = (a1 * a2 * a3 - 1000000LL);
            if( (nom % den) != 0)
               continue;
            long long a4 =  nom / den;
            if(a4 < a3)
               continue;
            if( (a1 + a2 + a3 + a4) <= 2000) {
               printf("%.2f %.2f %.2f %.2f\n", 
               a1 / 100., a2 / 100., a3 / 100., a4 / 100.);
            }
         }
      }
   }

   return 0;
}