#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
 
using namespace std;

vector<int> G[55];

int grafo( string g ) {
    int pai, filho, p, j;

    pai = (int)( g[1]-48 );
    if( isdigit( g[2] ) ) pai = pai*10 + (int)( g[2]-48 );

    for( int i=2; i<g.size()-1; i++ )
        if( g[i] == ' ' ) {
            p = 0;
            j = i+1;
            do {
                if( g[j] == '(' ) p++;
                if( g[j] == ')' ) p--;
                j++;
            } while( p );
            filho = grafo( g.substr( i+1, j-i-1 ) );
            G[pai].push_back( filho );
            G[filho].push_back( pai );
            i = j-1;
        }

    return pai;
}

int main() {
    int pai;
    bool espaco;
    string g;

    while( getline( cin, g ) ) {
        for( int i=1; i<=50 ; i++ ) G[i].clear();
        espaco = false;

        grafo( g );

        for( int k=1; k<=50; k++ )
            for( int i=1; i<=50; i++ )
                if( G[i].size() == 1 ) {
                    pai = G[i][0];
                    cout << ( espaco ? " " : "" ) << pai, espaco = true;
                    for( int j=0; j<G[pai].size(); j++ )
                        if( G[pai][j] == i )
                            G[pai].erase( G[pai].begin()+j );
                    
                    G[i].clear();
                    break;
                }

        cout << endl;
    }

    return 0;
}
