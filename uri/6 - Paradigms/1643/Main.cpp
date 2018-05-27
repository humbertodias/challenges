#include <iostream>
#include <cassert>
#include <stdint.h>

using namespace std;


int main(){
   uint32_t kase;
   uint32_t fibs[100];
   fibs[1] = 1; fibs[2] = 2;
   uint16_t k=2;
   while( (uint64_t)fibs[k]+(uint64_t)fibs[k-1] <= (1ULL<<32) ){
      ++k;
      fibs[k] = fibs[k-1] + fibs[k-2]; 
   }
   cin>>kase;
   while(kase--){
      uint32_t miles,km=0;
      cin>>miles;
      assert(miles > 2);
      uint16_t i=k;  
      while( i > 1 ){
         if(fibs[i] <= miles){
            miles    -= fibs[i];
            km    += fibs[i-1];  
         }
         --i;  
      }
      cout<<km<<endl;
   }
}