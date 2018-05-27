#include <stdio.h>

int main(){
    int x, s = 0, z, n = 0, i;
    scanf("%d", &x);
    while(scanf("%d", &z) && z <= x) ;

    for (i = x; s <= z; i++){
        s += x++;
        n++;
    }

    printf("%d\n", n);

    return 0;
}