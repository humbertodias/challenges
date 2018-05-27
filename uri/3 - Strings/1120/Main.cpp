#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int n, i, j, k, zero, cont;
    long long int num;
    char number[101];
    
    while(cin >> n){
        cin >> number;
        
        if(n == 0 && number[0] == '0') break;
        
        char changed[101];
        i = 0;
        j = 0;
        zero = 0;
        num = 0;
        cont = 0;
        while(true){
            if(number[i] == '\0'){
                break;
            }
            else if(number[i] == n+48){
                i++;
            }
            else{
                changed[j] = number[i];
                if(j == zero) cont++;
                if(number[i] == '0') zero++;
                i++;
                j++;
            }
        }
        changed[j] = '\0';
        
        stringstream f(changed);
        f >> num;
        
        if(j == 0){ cout << "0\n"; }
        else if(j == zero){ cout << num << "\n"; }
        else if(cont > 0){
            for(k = cont-1; changed[k] != '\0'; k++){
                cout << changed[k]-48;
            }
            cout << "\n";
        }
        else cout << changed << "\n";
    }
    
    return 0;
}