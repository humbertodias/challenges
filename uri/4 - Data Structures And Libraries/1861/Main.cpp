#include <iostream>
#include <cstdio>
#include <map>
#include <string>
 
using namespace std;

map<string,int> mapa;
map<string,bool> morto;
map<string,int>::iterator it;

int main() {
    string s1, s2;

    while( cin >> s1 >> s2 ) {
        mapa[ s1 ]++;
        morto[ s2 ] = true;
    }
    cout << "HALL OF MURDERERS\n";
    for( it=mapa.begin(); it!=mapa.end(); it++ )
        if( !morto[ it->first ] )
            cout << it->first << " " << it->second << endl;

    return 0;
}