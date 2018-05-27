#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n, x, y, s, i;
    cin >> n;
    while (n--){
        s = 0;
        cin >> x;
        cin >> y;

        if (x % 2 == 0) x++;

        for (i = 0; i < y; i++, x += 2) s += x;

        cout << s << endl;
    }
    return 0;
}