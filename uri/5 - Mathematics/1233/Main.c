#include <stdio.h>
#include <math.h>

unsigned int N;

void fatoracao() {
    int g = N, a;
    int gPow = pow(g, 0.5);
    for (a = 2; a <= gPow ; a++) {
        if (g == 1) break;
        if (g%a == 0) N = N/a*(a-1);
        while (g%a == 0) g/=a;
    }
    if (g != 1) N = N/g*(g-1);
}

int main() {
    while (scanf("%d", &N) != EOF) {
        fatoracao();
        printf("%d\n", N/2);
    }
    return 0;
}