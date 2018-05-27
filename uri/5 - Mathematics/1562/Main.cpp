#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int>vetor(10000);
map<int,int>mymap;

void funcao(int a,int n){
   if(a<n){
      if(vetor[a]==0 && vetor[mymap.find(a+1)->second-1]==0){
         vetor[a]=mymap.find(a+1)->second;
         vetor[mymap.find(a+1)->second-1]=a+1;
      }
   funcao(a+1,n);
   
   }
}
 
int main() {
   
   int n,aux;
   while(cin >> n){
            
      for(int i=0; i<n; i++)
         vetor[i]=0;
      
      for(int i=0; i<n; i++){
         cin >> aux;
         mymap[i+1]=aux;
      }

      funcao(0,n);
      if(n%2!=0)
         cout << "IMPOSSIBLE" << endl;
      else{
         int i=0;
         for(i=0; i<n; i++){
            if(vetor[i]==0)
               break;
         }
      
         if(i!=n)
            cout << "IMPOSSIBLE" << endl;
         else{
            for(int i=0; i<n; i++){
               cout << vetor[i];
               if(i==n-1)
                  cout << endl;
               else   
                  cout << " ";
         
         }
      }
      }
   }
   
    return 0;
}