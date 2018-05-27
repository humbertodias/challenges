#include <iostream>

using namespace std;

int main(){
    int n, i;
    int aux = 0;
    int pos = 0;
    
    for(i = 0; i < 100; i++){
        cin >> n;
        if(n > aux){
         aux = n;
         pos = i;
        }
    }
    
    cout << aux << "\n" << pos+1 << "\n";
    
    return 0;
}