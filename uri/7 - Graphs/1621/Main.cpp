// tema: grafos, bfs
// complexidade: O( 2*(N*M) )
// solução: baseando-se em um teorema que eu não lembro como era,
//          basta escolher o ponto A mais distante de um ponto qualquer B,
//          e a partir deste ponto A encontrar o ponto mais distante dele, C.
//          A distancia entre A e C é a resposta do problema.

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> ii;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
char matriz[510][510];
bool visi[510][510];

pair<ii, int> bfs(ii u);
bool limite(ii u);

int main() {
    while(1) {
        // lendo
        scanf("%d %d", &n, &m); if(!n) break;
        
        // lendo
        for(int i=0; i<n; i++) {
            //~ scanf("%s", matriz[i]);
            cin >> matriz[i];
        }
        
        // buscando
        ii start; bool ok = false;
        for(int i=0; i<n*m; i++) if(matriz[i/n][i%n] == '.') {
            start.first = i/n;
            start.second = i%n;
            
            pair<ii, int> v = bfs(start);
            if(v.second) {
                v = bfs(v.first);
                printf("%d\n", v.second);
                ok = true;
            }
            break;
        }
        if(!ok) printf("beep\n");
    }
}

pair<ii, int> bfs(ii start) {
    int dist = 0;
    queue<pair<ii, int> > q;
    while(!q.empty()) q.pop();
    q.push(make_pair(start, 0));
    for(int i=0; i<n; i++) memset(visi[i], false, sizeof(bool)*m);
    while(!q.empty()) {
        pair<ii, int> v = q.front(); q.pop();
        ii u = v.first;
        if(visi[u.first][u.second]) continue;
        visi[u.first][u.second] = true;
        
        if(matriz[u.first][u.second] == '.' && v.second > dist) {
            dist = v.second;
            start = u;
        }
        
        for(int i=0; i<4; i++) {
            ii new_u;
            new_u.first = u.first+dx[i];
            new_u.second = u.second+dy[i];
            
            if(limite(new_u) && matriz[new_u.first][new_u.second] != '#') {
                q.push(make_pair(new_u, v.second+1));
            }
        }
    }
    return make_pair(start, dist);
}

bool limite(ii u) {
    if(u.first < 0 || u.second < 0 || u.first >= n || u.second >= m)
        return false;
    else
        return true;
}
