#include <iostream>

using namespace std;

int main(){
    unsigned long long int p;

    while(cin >> p && p != - 1){
        if(p > 0)
            cout << p-1 << endl;
        else 
            cout << 0 << endl;
    }

    return 0;
}