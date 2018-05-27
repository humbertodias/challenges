#include <iostream>

using namespace std;

int main(){
    int a, b, c, aux=0;
    
    cin >> a >> b >> c;
    
    if(a > b)
    	aux = a;
    else
	    aux = b;
    
    if(aux > c)
        aux = aux;
    else
        aux = c;
    
    cout << aux << " eh o maior" << endl;
    return 0;
}