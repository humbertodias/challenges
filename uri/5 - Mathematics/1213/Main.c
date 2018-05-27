#include <stdio.h>

int howManyOnes(int num) {
    long div = 1;
    int resto, count = 1;
    
    while (1) {
        if (div < num) {
            div = div*10 + 1;
            count++;
        } 
       
        resto = div % num;

        if (resto == 0)
            break;    
        else
            div = resto;    
    }

    return count;
}

int main() {
    int num;
        
    while(scanf("%d", &num) != EOF)
        printf("%d\n", howManyOnes(num));

    return 0;
} 