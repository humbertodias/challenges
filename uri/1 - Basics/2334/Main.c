#include <stdio.h>

int main(){
    unsigned long long int p;

    while( scanf("%llu", &p) !=0 && p != - 1){
        if(p > 0)
            printf("%llu\n", p-1);
        else 
            printf("%d\n", 0);
    }

    return 0;
}