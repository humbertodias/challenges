#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
#define DFS_WHITE -1
 
using namespace std;
 
vector<int> S, visited, AdjList[100010], dfs_num, dfs_low, scc;
int dfsNumberCounter, numSCC;
 
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
 
    visited[u] = 1;
 
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
 
        if (dfs_num[v] == DFS_WHITE) {
            tarjanSCC(v);
        }
 
        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
 
    if (dfs_low[u] == dfs_num[u]) {
        //printf("SCC %d:", ++numSCC);
 
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            scc[v] = numSCC;
            //printf(" %d", v);
            if (u == v) break;
        }
        //printf("\n");
        numSCC++;
    }
}
 
vector<int> topoSort;
 
void dfs(int u){
    dfs_num[u] = 1;
 
    for(int i=0; i<AdjList[u].size(); i++){
        int v = AdjList[u][i];
 
        if(dfs_num[v] == DFS_WHITE){
            dfs(v);
        }
    }
 
    topoSort.push_back(u);
}
 
int main() {
    int N, M, U, V;
 
    cin >> N >> M;
 
    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        AdjList[U].push_back(V);
    }
 
    scc.assign(N+1, 0);
    visited.assign(N+1, 0);
    dfs_num.assign(N+1, -1);
    dfs_low.assign(N+1, 0);
    dfsNumberCounter = numSCC = 0;
 
    for (int i = 1; i <= N; i++) {
        if (dfs_num[i] == -1) {
            tarjanSCC(i);
        }
    }
 
    bool adjMat[numSCC][numSCC];
    memset(adjMat, false, sizeof(adjMat));
//    vector<int> newAdjList[numSCC];
    std::vector<int> newAdjList[100010];

    for(int u=1; u<=N; u++){
        for(int i=0; i<AdjList[u].size(); i++){
            int v = AdjList[u][i];
 
            if(scc[u] != scc[v] and !adjMat[scc[u]][scc[v]]){
                adjMat[scc[u]][scc[v]] = true;
                newAdjList[scc[u]].push_back(scc[v]);
            }
        }
    }
 
    for(int i=0; i<numSCC; i++){
        AdjList[i] = newAdjList[i];
    }
 
    topoSort.clear();
    dfs_num.assign(N+1, DFS_WHITE);
 
    for(int i=0; i<numSCC; i++){
        if(dfs_num[i] == DFS_WHITE){
            dfs(i);
        }
    }
 
    reverse(topoSort.begin(), topoSort.end());
 
    bool bolada = true;
 
    for(int i=0; i<numSCC-1; i++){
        if(!adjMat[topoSort[i]][topoSort[i+1]]){
            bolada = false;
            break;
        }
    }
 
    printf("%s\n", bolada ? "Bolada" : "Nao Bolada");
    return 0;
}