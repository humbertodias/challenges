#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 1001;

int n, m, k;
vector<int> adj[MAXN];
vector<int> chaves[MAXN];

bool visi[MAXN];
bool livre[MAXN];
bool aberto[MAXN];

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i=1; i<=n; i++) {
            adj[i].clear();
            chaves[i].clear();
        }
        
        for(int i=0; i<m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for(int i=2; i<=n; i++) {
            int a;
            scanf("%d", &a);
            
            chaves[a].push_back(i);
        }
        memset(visi, false, sizeof(visi));
        memset(livre, false, sizeof(livre));
        memset(aberto, false, sizeof(aberto));
        
        queue<int> q;
        while(!q.empty()) q.pop();
        q.push(1);
        livre[1] = aberto[1] = true;
        
        int cont = 0;
        while(!q.empty() and cont < n) {
            int u = q.front(); q.pop();
            
            if(visi[u]) continue;
            visi[u] = true;
            cont++;
            
            for(int i=0; i<(int)adj[u].size(); i++) {
                if(!livre[ adj[u][i] ] and aberto[ adj[u][i] ]) {
                    q.push( adj[u][i] );
                }
                
                livre[ adj[u][i] ] = true;
            }
            for(int i=0; i<(int)chaves[u].size(); i++) {
                if(!aberto[ chaves[u][i] ] and livre[ chaves[u][i] ]) {
                    q.push( chaves[u][i] );
                }
                
                aberto[ chaves[u][i] ] = true;
            }
        }
        
        printf("%s\n", cont == n ? "sim" : "nao");
    }
}
