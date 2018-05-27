#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> //memset
#include <queue>

#define ll long long

using namespace std;

int main(){

	int n,m;
	int v[10005];
	cin >> n >> m;
	for(int i=1;i<=n;i++) 
		cin >> v[i];

	int ans = 0;
	priority_queue< pair<int, int> > fila;

	for(int i=1; i<=n; i++) fila.push(make_pair(0,-i));
		while(m--){
			int c;
			cin >> c;
			int id = -fila.top().second;
			int l = -fila.top().first;
			fila.pop();
			fila.push(make_pair( -(l+v[id]*c), -id ));
			ans = max (ans, l+v[id]*c);
		}

		printf("%d\n", ans);
}