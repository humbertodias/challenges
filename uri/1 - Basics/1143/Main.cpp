#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, i;
    cin >> a;
    
    for(i = 0; i < a; i++){
    	cout << i+1 << " " << pow(i+1,2) << " " << pow(i+1,3) << endl;
	}
    return 0;
}