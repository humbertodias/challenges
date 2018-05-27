#include <set>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
 
#define MAXN 102
#define BRANCO 0
#define CINZA 1
#define PRETO 2
 
typedef pair<int,int> ii;
 
int dl[]={0,0,1,-1,1,1,-1,-1};
int dc[]={1,-1,0,0,1,-1,1,-1};
 
int main(){
int c,m,n,x,y,parede[MAXN][MAXN],cor[MAXN][MAXN],aumento[MAXN][MAXN];
queue<ii> fila;
ii soco;
 
scanf("%d",&c);
for(int i=1;i<=c;i++){
scanf("%d%d%d%d",&m,&n,&x,&y);
 
soco=make_pair(x,y);
for(int j=1;j<=m;j++){
    for(int z=1;z<=n;z++){
        scanf("%d",&parede[j][z]);
        cor[j][z]=BRANCO;
    }
}
 
ii atual;
cor[x][y]=CINZA;
aumento[x][y]=10;
fila.push(soco);
while(!fila.empty()){
    atual=fila.front();
    fila.pop();
    for(int j=0;j<8;j++){
      int nl=dl[j]+atual.first;
      int nc=dc[j]+atual.second;
      if(nl>=1 && nl<=m && nc>=1 && nc<=n){
        if(cor[nl][nc]==BRANCO){
            cor[nl][nc]=CINZA;
            fila.push(make_pair(nl,nc));
            if(aumento[atual.first][atual.second]>1) aumento[nl][nc]=aumento[atual.first][atual.second]-1;
            else aumento[nl][nc]=1;
        }
      }
    }
    cor[atual.first][atual.second]=PRETO;
}
 
printf("Parede %d:\n",i);
for(int j=1;j<=m;j++){
     for(int z=1;z<=n;z++){
            if(z==1) printf("%d",parede[j][z]+aumento[j][z]);
            else printf(" %d",parede[j][z]+aumento[j][z]);
    }
    printf("\n");
}
}
return 0;
}