#include <stdio.h>

int main(){
    int x, y;
    int op;
    int inter = 0;
    int gremio = 0;
    int grenal = 0;
    int empate = 0;
    
    while(1){

      scanf("%d", &x);
      scanf("%d", &y);

      if(x > y) inter ++;
      if(x < y) gremio ++;
      if(x == y) empate++;
      grenal++;
      
      printf("Novo grenal (1-sim 2-nao)\n");
      scanf("%d", &op);
      
      if(op == 2) break;
    }

    printf("%d grenais\n", grenal);
    printf("Inter:%d\n" ,inter );
    printf("Gremio:%d\n" , gremio );
    printf("Empates:%d\n" ,empate );
    
    if(inter > gremio) printf("Inter venceu mais\n");
    if(inter < gremio) printf("Gremio venceu mais\n");
    if(inter == gremio) printf("Nao houve vencedor\n");
    
    return 0;
}