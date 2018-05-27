#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
 
using namespace std;

struct crianca {
    string nome;
    int num;

    crianca( string nome, int num ) {
        this->nome = nome;
        this->num = num;
    }
};

vector<crianca> lc;

int validar( int i, int num, int tam ) {
    i = ( num&1 ? i+num : i-num );
    while( i >= tam ) i -= tam;
    while( i < 0 ) i += tam;
    return i;
}

int main() {
    int n, num, p;
    string nome;

    while( cin >> n && n ) {
        for( int i=0; i<n; i++ ) {
            cin >> nome >> num;
            lc.push_back( crianca( nome, num ) );
        }
        p = validar( 0, lc[0].num, lc.size() );
        while( lc.size() > 1 ) {
            crianca A = lc[p];
            lc.erase( lc.begin()+p );

            if( A.num&1 ) p--;
            p = validar( p, A.num, lc.size() );
        }

        cout << "Vencedor(a): " << lc[0].nome << endl;
        lc.clear();
    }

    return 0;
}