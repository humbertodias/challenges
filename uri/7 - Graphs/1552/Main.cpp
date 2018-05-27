#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define INF 0x3F3F3F3F
#define MAXN 500

using namespace std;

pair<int,int> p[MAXN];
int   n;
int pa[MAXN];
double graph[MAXN][MAXN];
double tree[MAXN], dist[MAXN];
double cost;


double distancia(int x1, int y1, int x2, int y2){
    return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}

void prim (){
    int v0;
    cost = 0;
    for (int i = 1; i < n; ++i){
        pa[i] = -1;
        tree[i] = 0;
        dist[i] = graph[0][i];
    }

    pa[0] = 0;
    while (1){
        double mincost = INF;
        for (int i = 0; i < n; ++i)
            if (pa[i] == -1 && mincost > dist[i])
                mincost = dist[v0 = i];
        if (mincost == INF)
            break;
        pa[v0] = tree[v0];
        cost += mincost;
        for (int i = 0; i < n; ++i)
            if (pa[i] == -1 && dist[i] > graph[v0][i]){
                dist[i] = graph[v0][i];
                tree[i] = v0;
            }
    }
}

int main(){
    int c;

    cin >> c;
    while(c--){
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i].first >> p[i].second;
        
        memset(graph, INF, sizeof(graph));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = distancia(p[i].first, p[i].second, p[j].first, p[j].second);

        prim();
        printf("%.2f\n", cost/100);
    }
}