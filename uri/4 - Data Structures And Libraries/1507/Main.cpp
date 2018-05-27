#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,q,pos;
    string base,s;
    cin >> n;
    while(n--){
        base.clear();
        cin >> base;
        cin >> q;
        while(q--){
            s.clear();
            cin >> s;
            pos = 0;
            for (int i = 0; i < s.size(); ++i){
                pos = base.find_first_of(s[i],pos);
                if(pos == -1)
                    break;
                pos++;
            }
            if(pos == -1)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}