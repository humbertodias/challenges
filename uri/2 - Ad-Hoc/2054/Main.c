#include <stdio.h>

int fil[6];

int main() {
    int T, t, i;
    scanf("%d", &T);
    
    for (t = 0; t < T; t++) {
        for (i = 0; i < 6; i++) scanf("%d", &fil[i]);
        
        int sum = 0;
        int invert = 1;
        
        for (i = 0; i < 6; i++) {
            sum ^= fil[i];
            if (fil[i] > 1) invert = 0;
        }
        
        printf("Instancia %d\n", t+1);
        
        if (!sum && !invert) printf("nao");
        else if (!sum && invert) printf("sim");
        else if (sum && !invert) printf("sim");
        else if (sum && invert) printf("nao");
        
        printf("\n");
        if(t != T-1)
        printf("\n");    }
    
    return 0;
}