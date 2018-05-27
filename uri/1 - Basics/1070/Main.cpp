#include <iostream>
using namespace std;

int main(){
    int x, i, j;
    
    cin >> x;
    
    for(i = x, j=0; j < 6; i++){
        if(i%2 != 0){
           cout << i << "\n";
           j++;
        }
    }
    return 0;
}