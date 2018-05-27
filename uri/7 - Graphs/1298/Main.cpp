#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define map(x,y) ((x-1)*n+y)
using namespace std;
int m,n;
char visitado[700][700];
struct no{
    int x,y,esq,dir,cima,baixo;
    no(int a,int b){
        x=a; y=b; esq=dir=cima=baixo=1;
    }
    no(){esq=dir=cima=baixo=0;};
};
no mat[700][700];
void bfs(int x, int y){
    queue<pair<int,int> > q;
    visitado[x][y]=1;
    q.push(pair<int,int>(x,y));
    while(!q.empty()){
        pair<int,int> v = q.front();q.pop();
        x = v.first;
        y = v.second;
        no atual=mat[x][y];
        if(atual.cima && x-1>=1 && !visitado[x-1][y]){
            q.push(pair<int,int>(x-1,y));
            visitado[x-1][y]=1;
        }
        if(atual.baixo && x+1<=m && !visitado[x+1][y]){
            q.push(pair<int,int>(x+1,y));
            visitado[x+1][y]=1;
        }
        if(atual.dir && y+1<=n && !visitado[x][y+1]){
            q.push(pair<int,int>(x,y+1));
           visitado[x][y+1]=1;
        }
 
        if(atual.esq && y-1>=1 && !visitado[x][y-1]){
            q.push(pair<int,int>(x,y-1));
           visitado[x][y-1]=1;
        }
    }
}
void solve(){
    memset(visitado,0,sizeof(visitado));
    int ans=0, i,j;
    for(i=1; i<=m;i++)
        for(j=1;j<=n;j++)
            if(!visitado[i][j]){
                ans++;
                bfs(i,j);
            }
    printf("%d\n",ans-1);
}
int main(){
    while(scanf("%d",&m)==1){
        n=2*m+1;
        m=2*m;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                mat[i][j]=no(i,j);
        for(int i=1;i<=m;i++){
            mat[i][1].esq=0;
            mat[i][n].dir=0;
        }
        for(int j=1;j<=n;j++){
            mat[1][j].cima=0;
            mat[m][j].baixo=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<=m/2;j++){
                char c; scanf(" %c",&c);
                if(c=='V'){
                    int xa=i, ya=2*j-1;
                    int xb=i, yb=2*j;
                    if(i%2==0) ya++, yb++;
                //  printf("removendo aresta (%d,%d)->(%d,%d)\n",xa,ya,xb,yb);
                    mat[xa][ya].dir=0;
                    mat[xb][yb].esq=0;
 
                    xa=i+1, ya=2*j-1;
                    xb=i+1, yb=2*j;
                    if(i%2==0) ya++, yb++;
                //  printf("removendo aresta (%d,%d)->(%d,%d)\n",xa,ya,xb,yb);
                    mat[xa][ya].dir=0;
                    mat[xb][yb].esq=0;
                }
                else{   
                    int xa=i, ya=2*j-1;
                    int xb=i+1, yb=2*j-1;
                    if(i%2==0) ya++, yb++;
                //  printf("removendo aresta (%d,%d)->(%d,%d)\n",xa,ya,xb,yb);
                    mat[xa][ya].baixo=0;
                    mat[xb][yb].cima=0;
 
                    xa=i, ya=2*j;
                    xb=i+1, yb=2*j;
                    if(i%2==0) ya++, yb++;
                //  printf("removendo aresta (%d,%d)->(%d,%d)\n",xa,ya,xb,yb);
                    mat[xa][ya].baixo=0;
                    mat[xb][yb].cima=0;
                }
            }
        }
        solve();
    }
    return 0;
}