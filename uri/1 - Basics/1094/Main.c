#include <stdio.h>

int main(){
    int n, q, i;
    char t;
    int total = 0;
    int coelho = 0;
    int sapo = 0;
    int rato = 0;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %c", &q,&t);
        
        total += q;
        
        if(t == 'C') coelho += q;
        if(t == 'S') sapo += q;
        if(t == 'R') rato += q;
    }
    
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelho);
    printf("Total de ratos: %d\n", rato);
    printf("Total de sapos: %d\n", sapo);
    printf("Percentual de coelhos: %.2f %%\n", ((float)coelho/(float)total)*100.00);
    printf("Percentual de ratos: %.2f %%\n", ((float)rato/(float)total)*100.00);
    printf("Percentual de sapos: %.2f %%\n", ((float)sapo/(float)total)*100.00);
    return 0;
    
}