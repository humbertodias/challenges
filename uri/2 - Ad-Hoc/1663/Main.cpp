// Problem   Ambiguous Permutations
// Algorithm straight-forward
// Runtime   O(n)

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#define MAXN 200000

int perm[MAXN+1];
bool used[MAXN+1];

int main() {
    int n;
    while( cin >> n && n > 0 ) {
        // some asserts
        assert( n <= 100000 );
        for ( int i=1; i <= n; i++ )
            used[i] = false;

        // read the permutation
        for ( int i=1; i <= n; i++ ) {
            cin >> perm[i];

            // some asserts
            assert( perm[i] >= 1 && perm[i] <= n );
            assert( !used[perm[i]] );
            used[ perm[i] ] = true;
        }
        // check the permutation
        for ( int i=1; i <= n; i++ )
            if ( perm[i] != i && perm[ perm[i] ] != i ) {
                cout << "not ";
                break;
            }
        cout << "ambiguous" << endl;
    }
    assert( n == 0 );
    return 0;
}