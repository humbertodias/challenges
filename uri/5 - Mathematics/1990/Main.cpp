#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main(){
	int n, i;
	while(1){
		scanf("%d",&n);
		if(n == -1)	break;
 
		ll arr[n+5], s=0;
		for(i=1;i<n;i++){
			scanf("%lld", &arr[i]);
			s += arr[i];
		}
 
		sort(arr+1,arr+n);
		int c=0;
		ll m1 = arr[n/2], m2 = arr[n/2+1];
 
		ll x = m1*n - s;
		if(x<m1 && !binary_search(arr+1,arr+n/2+1,x))	c++;
 
		x = s/(n-1);
		if(x>m1 && x<m2 && s%(n-1)==0)	c++;
 
		x = m2*n - s;
		if(x>m2 && !binary_search(arr+n/2+1,arr+n,x))	c++;
 
		printf("%d\n",c);
	}
	return 0;
}