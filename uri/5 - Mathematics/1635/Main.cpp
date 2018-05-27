#include <iostream>
#include <map>
using namespace std;
 
map<string,double> mapa;
 
int main() {
    int p, a, t = 1, n;
    string nome;
    double adv, soma;
    bool r;
     
    cin >> p >> a;
    for( int i=0; i<p; i++ ) {
        cin >> nome >> adv;
        mapa[ nome ] = adv*100;
    }
    for( int i=0; i<a; i++ ) {
        soma = 0;
        while( true ) {
            cin >> nome;
            if( mapa.count( nome ) )
                soma += mapa[ nome ];
            else if( nome[0] == '<' || nome[0] == '>' || nome[0] == '=' )
                break;
        }
        cin >> n;
        n *= 100;
        if( nome == ">" ) r = ( soma-n > 0.0 );
        if( nome == ">=" ) r = ( soma-n >= 0.0 );
        if( nome == "<" ) r = ( soma-n < 0.0 );
        if( nome == "<=" ) r = ( soma-n <= 0.0 );
        if( nome == "=" ) r = ( soma-n == 0.0 );
        cout << "Guess #" << t++ << " was " << ( r ? "correct." : "incorrect." ) << endl;
    }
 
    return 0;
}