#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, zeros, uns, dzeros, duns;
    bool ord;
    string num;
    
    while( scanf( "%d", &n ) && n ) {
        while( n-- ) {
            ord = false;
            zeros = uns = dzeros = duns = 0;
            cin >> num;
            for( int i = 0; i < num.size(); i++ )
                ord ? uns += (int)( num[i] - '0' ) : zeros += (int)( num[i] - '0' ), ord = !ord;
            
            while( zeros ) {
                dzeros += zeros%10;
                zeros /= 10;
            }
            while( uns ) {
                duns += uns%10;
                uns /= 10;
            }
            printf( "%d\n", dzeros + duns );
        }
    }

    return 0;
}