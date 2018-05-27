#include <iostream>
#include <cstdio>

using namespace std;
int vitamin(string s){

    if( s == " suco de laranja" )
        return 120;
    else if (s == " morango fresco" )
        return 85;
    else if (s ==  " mamao")
        return 85;
    else if (s == " goiaba vermelha")
        return 70;
    else if(s == " manga")
        return 56;
    else if(s == " laranja")
        return 50;
     else
        return 34;

}

int main()
{

 int n,m;
    string a;

    while(cin >> n and n){
        int sum = 0;
            while(n--) {
        scanf("%d", &m);

        getline(cin , a);

        sum  +=  (m*(vitamin(a)));

        }

        if(sum >= 110 and sum <= 130)
            cout << sum << " mg" << endl;
        else if (sum > 130)
            cout << "Menos " << sum - 130 << " mg" << endl;
        else
            cout << "Mais " << 110 - sum << " mg" << endl;
    }
    return 0;
}