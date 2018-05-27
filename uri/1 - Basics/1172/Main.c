#include <stdio.h>

int main(){
    int i, n, nok;
    for(i = 0; i < 10; i++){
            nok = scanf("%d", &n);
            if(n <= 0 || nok == -1) n = 1;
            printf("X[%d] = %d\n", i, n) ;
    }
    return 0;
}