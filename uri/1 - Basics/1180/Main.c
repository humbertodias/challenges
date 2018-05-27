#include <stdio.h>

int main(){
    int c, n, m, im = 0, i = 0;
    scanf("%d %d",&c, &n);
    m = n;
    while(c--){
        i++;
        scanf("%d",&n);
        if (n < m){
            im = i;
            m = n;
        }
    }
    printf("Menor valor: %d\n", m);
    printf("Posicao: %d\n", im);
    return 0;
}