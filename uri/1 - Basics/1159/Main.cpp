#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int x, s, i;

    while (scanf("%d", &x) && x != 0){
        s = 0;

        if (x % 2 != 0) x++;

        for (i = 0; i <= 4; i++, x += 2) s += x;

        cout << s << endl;
    }
    return 0;
}