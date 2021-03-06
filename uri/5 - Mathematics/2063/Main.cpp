#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm> // __gcd

#define ll long long 
using namespace std;

int main() {
    int n;
    int G[105];

    int res=1;
    cin >> n;
    for(int i=1; i<=n;i++)
        cin >> G[i];

    for(int i=1;i<=n;i++){
        int p = G[i];
        int t = 1;
        while(p!=i){
            t++;
            p = G[p];
        }
        res = (res/ __gcd(res,t)) * t;
    }
    cout << res << endl;

    return 0;
}
