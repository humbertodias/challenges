#include <iostream>

using namespace std;

int main(){
    int a,b, aux, i;
    
    cin >> a >> b;
    
    if(b < a){
      aux = a;
      a = b;
      b = aux;
    }
    
    for(i = a+1; i < b; i++){
        if(i%5 == 2 || i%5 == 3){
           cout << i << endl;
        }
    }
    return 0;
}