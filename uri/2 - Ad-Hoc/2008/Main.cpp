#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;

int memo[400][10005];

struct member{
    int cost, red, blue;
    member(){}
    member(int _c, int _r, int _b):cost(_c), red(_r), blue(_b){}

};

int solve(int idx,int budget, vector<member> &m, bool f){
    if(idx == m.size()) return 0;
    if( memo[idx][budget] != -1) return memo[idx][budget];
    int ans = 0;
    if( f ){
        ans = max(ans, solve(idx + 1, budget, m, f) + m[idx].blue);
        if( budget - m[idx].cost >= 0)
            ans = max(ans, solve(idx + 1, budget -  m[idx].cost, m, f) + m[idx].red);
    }else{
        ans = max(ans, solve(idx + 1, budget, m, f) + m[idx].red);
        if( budget - m[idx].cost >= 0)
            ans = max(ans, solve(idx + 1, budget -  m[idx].cost, m, f) + m[idx].blue);
    }
    return memo[idx][budget] = ans;
}

void dfs(int node, vector<vector<int> > &GD, vector<vector<int> > &GP, vector<bool> &vD, vector<bool> &vP, vector<int> &costD, vector<int> &costP, member &tmp, int color ){
    if( color ){
        vP[node] = true;
        tmp.red++;
        tmp.cost += costP[node];
        for(int i  = 0; i < GP[node].size(); i++){
            int current = GP[node][i];
            if( vD[current] ) continue;
            dfs(current, GD, GP, vD, vP, costD, costP, tmp, 0);
        }
    }else{
        vD[node] = true;
        tmp.blue++;
        tmp.cost += costD[node];
        for(int i  = 0; i < GD[node].size(); i++){
            int current = GD[node][i];
            if( vP[current] ) continue;
            dfs(current, GD, GP, vD, vP, costD, costP, tmp, 1);
        }
    }
}

int main(){
    int d,p,r,b,u,v;
    while( cin >> d >> p >> r >> b ){

        vector<int> costD(d),costP(p);
        vector<bool> vD(d), vP(p);
        vector<vector<int> > GD(d), GP(p);

        for(int i = 0; i < d; i++) cin >> costD[i];
        for(int i = 0; i < p; i++) cin >> costP[i];

        for(int i = 0; i < r; i++){
            cin >> u >> v;
            u--;
            v--;
            GD[u].push_back(v);
            GP[v].push_back(u);
        }

        vector<member> members;
        for(int i = 0; i < d; i++){
            if(vD[i]) continue;
            member tmp = member(0,0,0);
            dfs(i, GD, GP, vD, vP, costD, costP, tmp, 0);
            members.push_back(tmp);
        }

        for(int i = 0; i < p; i++){
            if(vP[i]) continue;
            member tmp = member(0,0,0);
            dfs(i, GD, GP, vD, vP, costD, costP, tmp, 1);
            members.push_back(tmp);
        }

        memset(memo, -1, sizeof memo);
        cout << solve(0, b, members, 1) << " ";
        memset(memo, -1, sizeof memo);
        cout << solve(0, b, members, 0) << endl;
    }
}