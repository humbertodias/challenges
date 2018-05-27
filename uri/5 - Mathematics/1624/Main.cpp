#include <cstdio>
#include <cstdlib>

int main(){
  int N, p[1000], P[1000], M, soma=0, i, peso=0;

  while(scanf("%d", &N), N){

    for(i=0; i<N; i++){
        scanf("%d %d", &p[i], &P[i]);
    }

    scanf("%d", &M);

    i=0;
    while((peso<=M)&&(i<N)){

        peso=peso+P[i];
        soma=soma+p[i];

        if(peso>M){
            peso=peso-P[i];
            soma=soma-p[i];
        }

        i++;
    }
    printf("%d\n", soma);
    peso=0, i=0, soma=0, M=0;
  }
  
}