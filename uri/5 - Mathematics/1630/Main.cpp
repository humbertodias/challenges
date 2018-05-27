#include <iostream>
#include <cstdio>

using namespace std;

#define ll long long

ll gcd( ll a, ll b ) { return b == 0 ? a : gcd( b, a%b ); }

int main() {
	ll a, b, mdc;

	while( scanf( "%lld%lld", &a, &b ) != EOF ) {
		mdc = gcd( a, b );
		a /= mdc;
		b /= mdc;
		printf( "%lld\n", 2*a + 2*b );
	}

	return 0;
}