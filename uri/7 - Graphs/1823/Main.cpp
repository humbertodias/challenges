#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>

#define MAXN 1010
using namespace std;
 
map<int, int>trad;
int n, xi, yi, xf, yf, coord[4*MAXN], sz, x[2*MAXN], y[2*MAXN];
bool mapa[4*MAXN][4*MAXN][4], jav[4*MAXN][4*MAXN];
 
bool dfs(int i, int j){
    if(jav[i][j]) return false;
    if(i==xf-1&&j==yf-1) return true;
    jav[i][j] = true;
    bool ans = false;
    if(mapa[i][j][0]) ans |= dfs(i+1,j);
    if(mapa[i][j][1]) ans |= dfs(i-1,j);
    if(mapa[i][j][2]) ans |= dfs(i,j+1);
    if(mapa[i][j][3]) ans |= dfs(i,j-1);
    return ans;
}
 
int main(){
    int teste = 1;
    while(scanf("%d",&n)){
        if(n<0) break;
        scanf("%d%d%d%d",&xi,&yi,&xf,&yf);
        trad.clear();
        sz = 0;
        coord[sz++] = xi; coord[sz++] = xf; coord[sz++] = yi; coord[sz++] = yf;
        memset(mapa, true, sizeof(mapa)); ///0 -> direita; 1 -> esquerda; 2 -> cima; 3 -> baixo
        memset(jav, false, sizeof(jav));
        for(int i = 0; i < 2*n; i++){
            scanf("%d %d", &x[i], &y[i]);
            coord[sz++]= x[i];
            coord[sz++] = y[i];
            if(i%2==1 && (x[i]<x[i-1] || y[i]<y[i-1])){
                swap(x[i], x[i-1]);
                swap(y[i], y[i-1]);
            }
        }
        sort(coord, coord+sz);
        if(1){
            int cnt = 2;
            trad[coord[0]] = 1;
            for(int i = 1; i < sz; i++){
                if(coord[i]==coord[i-1]) continue;
                trad[coord[i]] = cnt++;
            }
        }
        xi = trad[xi]; yi = trad[yi]; xf = trad[xf]; yf = trad[yf];
        for(int i = 0; i < 2*n; i++){
            x[i] = trad[x[i]];
            y[i] = trad[y[i]];
        }
        for(int i = 0; i <= xf+1; i++) mapa[i][yi][3] = mapa[i][yf-1][2] = false;
        for(int i = 0; i <= yf+1; i++) mapa[xi][i][1] = mapa[xf-1][i][0] = false;
        for(int i = 0, ini, fim; i < n; i++){
            ini = 2*i;
            fim = 2*i+1;
            if(x[ini]==x[fim]) for(int j = y[ini]; j < y[fim]; j++) mapa[x[ini]-1][j][0] = mapa[x[ini]][j][1] = false;
            else               for(int j = x[ini]; j < x[fim]; j++) mapa[j][y[ini]-1][2] = mapa[j][y[ini]][3] = false;
        }
        printf("Instancia %d\n%s\n\n", teste++, (dfs(xi, yi)?"sim":"nao"));
    }
}