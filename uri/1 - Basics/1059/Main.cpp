#include <iostream>

using namespace std;

int main(){
    int i;
    for(i = 2; i <= 100; i++)
        if(i%2 == 0)
            cout << i << "\n";
    return 0;
}