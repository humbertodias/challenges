#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct aresta {
    int no;
    int dist;
};

vector<aresta> adj[20010];
map<int,int> mapa;

int M, Q, N, c1, c2;
aresta aux;

int cur_cc;

int cc[20010];
int visitado[20010][2];
int pot[20010][2];

void DFS(int c1, int parity, int p) {
    if (visitado[c1][parity]) return;
    
    cc[c1] = cur_cc;
    visitado[c1][parity] = 1;
    pot[c1][parity] = p;
    
    for (int i = 0; i < adj[c1].size(); i++) {
        int np;
        
        if (parity == 0) np = p+adj[c1][i].dist;
        else np = p-adj[c1][i].dist; 
        
        DFS(adj[c1][i].no, 1-parity, np);
    } 
}

int main() {
    while (scanf("%d %d", &M, &Q) && M) {
        mapa.clear();
        N=0;
        for (int i = 0; i < M; i++) {
            int val;
            scanf("%d %d %d", &c1, &c2, &val);
            
            if (c1 == c2) val *= 2;
            
            int map1, map2;
            
            if (mapa.find(c1) == mapa.end()) {
                adj[N].clear();
                mapa[c1]=N++;
            }
            map1 = mapa[c1];
            
            if (mapa.find(c2) == mapa.end()) {
                adj[N].clear();
                mapa[c2]=N++;
            }
            map2 = mapa[c2];
            
            aux.dist = val;
            aux.no = map2;
            adj[map1].push_back(aux);
            
            aux.no = map1;
            adj[map2].push_back(aux);
        }
        
        memset(cc,0,sizeof(cc));
        memset(visitado,0,sizeof(visitado));
        
        cur_cc = 1;
        for (int i = 0; i < N; i++) {
            if (!cc[i]) {
                DFS(i,0,0);  
                cur_cc++;  
            }
        }
        
        for (int i = 0; i < Q; i++) {
            scanf("%d %d", &c1, &c2);
            
            if (mapa.find(c1)==mapa.end() || mapa.find(c2)==mapa.end()){
                printf("*\n");
                continue;
            }
            
            c1=mapa[c1];
            c2=mapa[c2];
            
            if (c1 == c2) {
                if (visitado[c1][0] && visitado[c1][1]) {
                    printf("%d\n", (pot[c1][1]-pot[c1][0])/2);
                }
                else printf("*\n");
                
                continue;
            }

            if (cc[c1] == cc[c2]) {
                if (visitado[c1][1] && visitado[c2][0]) {
                    printf("%d\n", pot[c1][1]-pot[c2][0]);
                    continue;
                }
                
                swap(c1,c2);
                
                if (visitado[c1][1] && visitado[c2][0]) {
                    printf("%d\n", pot[c1][1]-pot[c2][0]);
                    continue;
                }
            }
            
            if (visitado[c1][0] && visitado[c1][1]) {
                if (visitado[c2][0] && visitado[c2][1]) {
                    printf("%d\n", (pot[c1][1]-pot[c1][0]+pot[c2][1]-pot[c2][0])/2);
                    continue;
                }
            }
                
            printf("*\n");
        }
        
        printf("-\n");
    }
    
    return 0;       
}