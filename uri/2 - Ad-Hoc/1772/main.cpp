#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
  
bitset<32> num;
  
int main() {
    long long int n, menor, maior;
    int k, a, b;
  
    while( cin >> n >> k && k ) {
        int i = 0;
        num.reset();
        menor = maior = n;
          
        while( n ) {
            num.set( i++, n&1 );
            n >>= 1;
        }
        for( i=0; i<k; i++ ) {
            cin >> a >> b;
            if( num[a] != num[b] ) {
                num[a] = !num[a];
                num[b] = !num[b];
            }
            n = stoll( num.to_string(), NULL, 2 );
            menor = min( menor, n );
            maior = max( maior, n );
        }
        cout << n << " " << maior << " " << menor << endl;
    }
  
    return 0;
}