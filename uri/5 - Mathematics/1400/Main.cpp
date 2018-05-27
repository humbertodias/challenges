#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
int cont;
 
bool sete(int num){
    int aux;
    while(num){
        aux = num % 10;
        if(aux == 7)
            return true;
        num -= aux;
        num /= 10;
    }
 
    return false;
}
 
int main(){
    int n,m,k;
    int palmas;
// m-esima pessoa
// palma pela k-esima vez
 
    while(cin >> n >> m >> k, n + m + k){
        cont   = 0;
        palmas = 0;
        while(1) {
            for(unsigned i = 1; i < n; ++i) {
                cont++;
                if(i == m){
                    if(cont % 7 == 0)
                        palmas++;
                         
                    else if(sete(cont))
                        palmas++;
 
                    if(palmas == k)
                        break;
                }
            }
 
            if(palmas == k)
                break;
 
            for(unsigned i = n; i > 1; i--) {
                cont++;
                if(i == m){
                    if(cont % 7 == 0)
                        palmas++;
                         
                    else if(sete(cont))
                        palmas++;
 
                    if(palmas == k)
                        break;
                }
            }
 
            if(palmas == k)
                break;
        }

        cout << cont << endl;
    }
}