#include <iostream> // scanf,puts
#include <algorithm> // std::sort
#include <utility>
#include <cstring>// memset
#include <vector>

using namespace std;

int vis[1005];
int freq[2];

vector<vector<int> > v;

void dfs(int n, int cor)
{
	vis[n] = cor;
	++freq[cor];
	for (int i = 0 ; i < (int)v[n].size(); ++i)
		if (vis[v[n][i]] == -1) dfs(v[n][i], cor ^ 1); 
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	int u, v1;
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> n >> m;
		v.assign(n, vector<int>());
		
		for (int i = 0 ; i < m; ++i)
		{
			cin >> u >> v1;
			--u;
			--v1;
			v[u].push_back(v1);
			v[v1].push_back(u);
		}
		freq[0] = freq[1] = 0;
		for (int i = 0 ; i < n ; ++i) vis[i] = -1;
		
		dfs(0, 0);
		cout << max(freq[0], freq[1]) << '\n';
	}
}