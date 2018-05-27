#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
#include <map>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define pb push_back
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<string, string> ss;

struct node {
  string lang;
  char start;
  int dist;
  node(string s, char c, int d) : lang(s), start(c), dist(d) {}
  const bool operator<(node const &other) const {
    return dist > other.dist;
  }
};

void djikstra(map<string, vector<ss> > &edges, string start, string dest) {
  priority_queue<node> heap;
  int goalstep = INF;
  set < pair<string, char> > seen;
  heap.push(node(start, 0, 0));
  while(heap.size()) {
    node curr = heap.top();
    heap.pop();
    if (seen.find(mp(curr.lang, curr.start)) != seen.end()) continue;
    seen.insert(mp(curr.lang, curr.start));
    if (curr.lang == dest) {
      goalstep = min(goalstep, curr.dist);
    }
    else {
      for(int i=0; i < edges[curr.lang].size(); i++)
        if (edges[curr.lang][i].Y[0] != curr.start)
          heap.push(node(edges[curr.lang][i].X, edges[curr.lang][i].Y[0], 
            curr.dist + edges[curr.lang][i].Y.size()));
    }
  }
  if (goalstep > INF / 2) printf("impossivel\n");
  else printf("%d\n", goalstep);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T > 0) {
    map<string, vector<ss> > edges;
    char src[55], dest[55];
    scanf("%s %s", src, dest);
    for(int i=0; i < T; i++) {
      char x[55], y[55], z[55];
      scanf("%s %s %s", x, y, z);
      edges[x].pb(mp(y, z));
      edges[y].pb(mp(x, z));
    }
    djikstra(edges, src, dest);
    scanf("%d", &T);
  }
  return 0;
}