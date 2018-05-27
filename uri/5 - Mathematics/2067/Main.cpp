#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> //memset

#define ll long long

using namespace std;

int main(){
	int n,m,q;
	int grid[205][205];
	int dp[205][205];
	int maior = 0;
	memset(dp,0,sizeof dp);

	cin >> n >> m;
	for(int i=1; i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> grid[i][j];
			if(grid[i][j]==0) dp[i][j]=0;
			else{
				dp[i][j] = min(dp[i-1][j-1], 
					min(dp[i-1][j], dp[i][j-1]) ) +1;
				maior = max(maior, dp[i][j]);
			}
		}
	}

	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t <= maior) printf("yes\n");
		else printf("no\n");
	}

}