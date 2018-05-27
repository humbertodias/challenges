#include <stdio.h>
#include <string.h> //memset


#define somar(X,Y,Z,W, soma) int i, j; for (i = X; i <= Z; ++i)  for (j = Y; j <= W; ++j) soma += m[i][j];  
#define reset(m,x) int i; for (i = 0; i <= x; ++i) memset(m[i], 0, sizeof(int) * x);

int m[1001][1001];

int main(){
  int x,y,p,q,X,Y,N,Z,W,soma;
  char op;

  while(scanf("%d %d %d",&x,&y,&p) & (x&&y&&p )){
    reset(m,x);
    scanf("%d",&q);
    
    for(;q--;){
      scanf(" %c",&op);
      if('A'==op){
        scanf("%d %d %d",&N,&X,&Y);
        m[X][Y] += N;
      }
      else{
        scanf("%d %d %d %d",&X,&Y,&Z,&W);
        
        //colocar o menor no x e y
        if(Z < X){
          soma = Z;
          Z = X;
          X = soma;
        }
        if(W < Y){
          soma = W;
          W = Y;
          Y = soma;
        }

        somar(X,Y,Z,W, soma);
        printf("%d\n",soma*p);
      }
    }
    printf("\n");
  }
  return 0;
}