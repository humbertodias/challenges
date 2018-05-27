#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

int n;
string ord[20];
vector<int> id[20];
int newid;
vector<pair<int, int> > par;
vector<vector<int> > g;
vector<int> gradoin;
int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> n && n != -1) {
    par.clear();
    par.pb(mp(0, 0));
    newid = 0;
    for (int i = 2; i <= n; i++) {
      cin >> ord[i];
      id[i] = vector<int>(ord[i].size());
      for (int j = 0; j < ord[i].size(); j++) {
        if (ord[i][j] == '1') {
          id[i][j] = ++newid;
          par.pb(mp(1, i));
        }
      }
    }
    for (int i = 2; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        char A = '0' + i, B = '0' + j;
        int a = 0, b = 0;
        int sa = sz(ord[i]), sb = sz(ord[j]);
        while (a < sa && b < sb) {
          if (ord[i][a] == B) {
            if (ord[j][b] == A) {
              ++newid;
              id[i][a] = id[j][b] = newid;
              par.pb(mp(i, j));
              a++, b++;
            } else {
              b++;
            }
          } else {
            a++;
          }
        }
      }

    g = vector<vector<int> >(newid + 1, vector<int>());
    gradoin = vector<int>(newid + 1, 0);
    for (int i = 2; i <= n; i++)
      for (int j = 1; j < id[i].size(); j++) {
        int u = id[i][j - 1], v = id[i][j];
        g[u].pb(v);
        gradoin[v]++;
      }

    int N = newid;
    vector<int> ts;
    queue<int> q;
    for (int i = 1; i <= N; i++)
      if (gradoin[i] == 0)
        q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      ts.pb(u);
      for (int j = 0; j < g[u].size(); j++) {
        int v = g[u][j];
        gradoin[v]--;
        if (gradoin[v] == 0)
          q.push(v);
      }
    }

    string ans;

    for (int i = 0; i < sz(ts); i++)
      if (par[ts[i]].first == 1)
        ans.pb('0' + par[ts[i]].second);

    cout << ans << endl;
  }
  return 0;
}