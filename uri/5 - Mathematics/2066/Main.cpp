#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll pal(int x){
	x = x/2LL;
	ll res = 9LL;
	for(int i=1; i< x; i++) res *= 10LL;
		return res;
}

int main(){
	ll ans[20];
	ans[1] = 0LL;
	ans[2] = 36LL;
	for(int i=3; i<=18; i++){
		if(i%2==1){
			ans[i] = ans[i-1]*10LL;
		}else{
			ans[i] = ans[i-2]*100LL;
			ans[i] += 45LL*pal(i-2);
		}
	}
	int k;
	cin >> k;
	printf("%lld\n", ans[k]);
}