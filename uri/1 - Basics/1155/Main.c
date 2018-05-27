#include <stdio.h>

int main(){
    int i;
    double s = 1.0;
    for (i = 2; i <= 100; i++){
        s += 1.0 / (double) i;
    }
    printf("%.2lf\n", s);
    return 0;
}