#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll ele(ll x, ll y){
	ll res = 1;
	for(int i=0; i< y;i++)res *=x;
	return res;
}

int main(){
	ll a,b;
	cin >> a >> b;
	ll ans = 1;
	for(ll i = 2; i< 1000000LL; i++){
		ll ea = 0, eb = 0;
		while(a%i == 0){ea++; a/=i;}
		while(b%i == 0){eb++; b/=i;}
		ans *= ele (i, ((min(ea,eb)+(min(ea,eb)%2))/2LL) );
	}
	if(a==b) ans *= a;
	printf("%lld\n", ans);
}