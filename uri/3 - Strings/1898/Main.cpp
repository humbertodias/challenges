#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    double valor = 0.0;
    bool ponto;
    string s1, s2, cpf = "", v = "";
    stringstream ss;

    cin >> s1 >> s2;
    ponto = false;
    for( int i=0, j; i<s1.size(); i++ ) {
        if( isdigit( s1[i] ) || s1[i] == '.' ) {
            if( s1[i] != '.' && cpf.size() < 11 )
                cpf += s1[i];
            else {
                v += s1[i];
                if( ponto ) {
                    j++;
                    if( j == 2 ) break;
                }
                if( s1[i] == '.' ) ponto = true, j = 0;
            }
        }
    }
    valor += stod( v );
    v = "";
    ponto = false;
    for( int i=0, j; i<s2.size(); i++ ) {
        if( isdigit( s2[i] ) || s2[i] == '.' ) {
            v += s2[i];
            if( ponto ) {
                j++;
                if( j == 2 ) break;
            }
            if( s2[i] == '.' ) ponto = true, j = 0;
        }
    }
    valor += stod( v );
    
    cout.precision( 2 );
    cout << "cpf " << cpf << endl << fixed << valor << endl;

    return 0;
}
