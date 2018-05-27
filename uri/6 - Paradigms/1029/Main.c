#include <stdio.h>

int cont=0;
int fibonacci(int n){
    ++cont;
    if(n == 0 || n == 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    long fib;
    int n, o, i;
    scanf("%d",&n);
    for(i = 0; i < n; i++, cont=0){
            scanf("%d",&o);
            fib = fibonacci(o);
            printf("fib(%d) = %d calls = %ld\n",o,cont-1,fib);
    }
    return 0;
}

