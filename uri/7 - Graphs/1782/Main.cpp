#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define INF 1000000000
#define MAXV 100010
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
 
struct Conjunto {
    int pai;
    long long rank;
};
Conjunto v[MAXV];
int raiz(int u) {
    if(v[u].pai == u) return u;
    return v[u].pai = raiz(v[u].pai);
}
 
int main() {
    int t, i, n, p, teste = 1;
 
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
 
        for(i = 1; i <= n; ++i) {
            v[i].pai = i; v[i].rank = 1;
        }
 
        priority_queue< piii, vector<piii>, greater<piii> > q;
        for(i = 0; i < n-1; ++i) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            q.push(piii(w, pii(a, b)));
        }
 
        vector<int> query;
        scanf("%d", &p);
        while(p--) {
            int x; scanf("%d", &x);
            query.push_back(x);
        }
 
        printf("Caso #%d:", teste++);
        long long ans = n;
        int e = 0, w, a, b;
        sort(query.begin(), query.end());
        for(i = 0; i < (int)query.size(); ++i) {
            int maximo = query[i];
 
            while(e < n-1) {
                w = q.top().first;
                if(w > maximo) break;
 
                a = q.top().second.first; b = q.top().second.second;
                q.pop();
                int ra = raiz(a); int rb = raiz(b);
                if(ra == rb) continue;
 
                ans += (v[ra].rank * v[rb].rank);
 
                if(v[ra].rank < v[rb].rank)
                    swap(ra, rb);
 
                v[rb].pai = ra;
                v[ra].rank += v[rb].rank;
                e++;
            }
 
            printf(" %lld", ans);
        }
 
        printf("\n");
    }
 
    return 0;
}