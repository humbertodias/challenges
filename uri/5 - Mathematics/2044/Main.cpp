#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    while(1)
    {
       int n;
       cin >> n;
       if(n == -1)break;
       int x[n];
       for(int i = 0; i < n; ++i)cin >> x[i];
       for(int i = 1; i < n; ++i)x[i] += x[i - 1];
       int cnt = 0;
       for(int i = 0; i < n; ++i)if(x[i] % 100 == 0)cnt++;
       cout << cnt << endl;
    }
    return 0;
}