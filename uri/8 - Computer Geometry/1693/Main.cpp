#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main() {
	double R, H, V, G;

	while( scanf( "%lf%lf%lf%lf", &R, &H, &V, &G ) != EOF )
		printf( "%s\n", V/G*sqrt( V*V + 2.0*H*G ) - R > 0.01 ? "Y" : "N" );

	return 0;
}