#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;
int main(){

    double x,m;
    while( cin >> x >> m ){
    	if(x == 0 || m == 0) break;
        printf("%.0f\n", (m*x) );
    }

    return 0;

}
