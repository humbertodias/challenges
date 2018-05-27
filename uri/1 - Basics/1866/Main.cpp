#include <iostream>

using namespace std;

int main( ){

    int N, n, res;
    cin >> N;

    while(N--){

        cin >> n;
        res = 0;

        while(n--){
            if(n%2 == 0) res++;
            else res--;
        }

        cout << res << endl;

    }

    return 0;

}