#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;


int main(){
	ll t1, t2, n;
	cin >> t1 >> t2 >> n;
	ll in = (t2-t1)*60LL;

	ll total = in * in;
	ll en = total - (in-n) * (in-n);

	printf("%lld/%lld\n", en/__gcd(en,total)
		, total/__gcd(en,total));

}