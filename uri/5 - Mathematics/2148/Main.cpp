#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;

int s,d;
ll memo[100][100];

ll solve(int sum, int dados){
	if(dados==d){
		return sum == s;
	}
	if(sum >= s)
		return 0;
	if(memo[sum][dados] != -1)
		return memo[sum][dados];

	ll ans = 0;
	for(int i=1; i<= 6; i++)
		ans += solve(sum+i, dados+1);

	return memo[sum][dados]=ans;
}

int main(){

	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d %d", &s, &d);
		memset(memo, -1, sizeof memo);
		printf("%.15Lf\n", solve(0,0) / (long double)powl(6,d));
	}
	return 0;
}