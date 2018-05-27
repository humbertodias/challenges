#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 10000;

int n, m, s;
vector<int> adj[MAXN];

typedef struct Node {
    int id, friends, enemies, incoming;
    
    bool operator()(Node a, Node b) {
        if(a.enemies == b.enemies) {
            return a.friends < b.friends;
        } else {
            return a.enemies > b.enemies;
        }
    }
} Node;
Node node[MAXN];

int main() {
    priority_queue<Node, vector<Node>, Node> pq;
    
    while(scanf("%d %d %d", &n, &m, &s) != EOF and n) {
        for(int i=0; i<n; i++) {
            adj[i].clear();
            node[i].incoming = 0;
            node[i].id = i;
        }
        
        for(int i=0; i<n; i++) {
            scanf("%d", &node[i].enemies);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &node[i].friends);
        }
        
        for(int i=0; i<m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            
            adj[a].push_back(b);
            node[b].incoming++;
        }
        
        while(!pq.empty()) pq.pop();
        for(int i=0; i<n; i++) if(!node[i].incoming) {
            pq.push(node[i]);
        }
        
        int count = n;
        while(!pq.empty()) {
            Node u = pq.top(); pq.pop();
            
            if(u.enemies >= s) {
                break;
            }
            count--;
            s += u.friends;
            
            for(int i=0; i<(int)adj[u.id].size(); i++) {
                if(--node[ adj[u.id][i] ].incoming == 0) {
                    pq.push(node[ adj[u.id][i] ]);
                }
            }
        }
        
        printf("%s\n", count ? "impossivel" : "possivel");
    }
}
