#include <stdio.h>

long fib( long n) {
    if (n==0 || n==1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main() {
     long a, b, n, cont;
     long num;

    while(scanf("%ld %ld %ld", &a, &b, &n) && (a!=0 && b!=0 && n!=0) ) {
        num = 0;
        for( cont = 0; cont < n; cont++) {
            num += fib(a + cont) * fib(b + cont);
        }

        printf("%ld\n", num);
    }

    return 0;
}