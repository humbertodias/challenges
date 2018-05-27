#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

double log_pow( int a, int b ) {
    return b*log10( a );
}

double log_fat( int c ) {
    if( c == 1 ) return 0.0;
    return log10( c ) + log_fat( c-1 );
}

int main() {
    int n, a, b, c, lucas = 0, pedro = 0;
    stringstream ss;
    
    scanf( "%d", &n );
    for( int rodada = 1; rodada <= n; rodada++ ) {
        scanf( "%d^%d", &a, &b );
        scanf( "%d!", &c );
        double lp = log_pow( a, b ), lf = log_fat( c );
        if( lp != lf ) 
            lp > lf ? lucas++ : pedro++;
        ss << "Rodada #" << rodada << ": " << ( lp > lf ? "Lucas" : "Pedro" ) << " foi o vencedor\n";
    }
    if( lucas == pedro )
        printf( "A competicao terminou empatada!\n" );
    else
        printf( "Campeao: %s!\n", lucas > pedro ? "Lucas" : "Pedro" );
    cout << ss.str();
    
    return 0;
}
