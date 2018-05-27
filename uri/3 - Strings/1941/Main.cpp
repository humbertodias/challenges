#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define MAXN 2005
#define max3( a, b, c ) max( a, max( b, c ) )

struct sol {
    int tam, peso;
    void clear() { tam = peso = -1; }
    bool operator<( const sol &s ) const {
        if( peso == s.peso ) return tam < s.tam;
        else return peso < s.peso;
    }
};

sol dp[MAXN][MAXN];
bool p[MAXN];
string s;

sol lps( int l, int r ) {
    if( dp[l][r].tam != -1 ) return dp[l][r];

    if( l == r ) {
        dp[l][r].tam = 1;
        dp[l][r].peso = p[l];

    } else if( l + 1 == r ) {
        dp[l][r].tam = ( s[l] == s[r] ? 2 : 1 );
        dp[l][r].peso = ( s[l] == s[r] ? p[l] + p[r] : max( p[l], p[r] ) );
    
    } else {
        if( s[l] == s[r] ) {
            dp[l][r] = lps( l + 1, r - 1 );
            dp[l][r].tam += 2;
            dp[l][r].peso += p[l] + p[r];
        }
        dp[l][r] = max3( dp[l][r], lps( l, r-1 ), lps( l+1, r ) );
    }
    return dp[l][r];
}

int main() {
    int n, index;
    memset( p, 0, sizeof p );
    
    cin >> s >> n;
    for( int i = 0; i <= s.size(); i++ )
        for( int j = 0; j <= s.size(); j++ )
            dp[i][j].clear();

    for( int i = 0; i < n; i++ )
        cin >> index, p[index-1] = 1;

    printf( "%d\n", lps( 0, s.size()-1 ).tam );

    return 0;
}