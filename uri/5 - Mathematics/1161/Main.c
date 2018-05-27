#include <stdio.h> // printf

unsigned long fatorial(unsigned long n){
    unsigned long num = 1;
    while(n >= 1){
        num *= n;
        n -= 1;
    }
    return num;
}

int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     long m, n;

     while( scanf("%ld %ld", &m, &n) != EOF ){
          printf( "%ld\n", fatorial (m) + fatorial(n) );
     }
     return 0;
}
