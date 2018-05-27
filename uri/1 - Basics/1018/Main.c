#include <stdio.h>

int main(){
    int inteiro;
    scanf("%d", &inteiro);
    printf("%d\n", inteiro);
    int banknotes [] = {100, 50, 20, 10, 5, 2, 1};
    int aux = inteiro, div, i;
    for(i=0; i< 7;i++){
        div = banknotes[i];
        printf("%d nota(s) de R$ %d,00\n", aux/div, div );
        aux = aux % div;
    }

    return 0;
}