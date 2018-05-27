#include <stdio.h>
 
int main() {
 
    int n, m, i, j;
    int cc = 0, cf = 0;
    char a[10];
    char c[10] = "clicou\0";
    char f[10] = "fechou\0";
 
    scanf("%d %d\n", &n, &m);
 
    for(i=1; i<=m; i++) {
        gets(a);
        for(j=0;j<=5;j++)
        {
            if(a[j] == c[j])
                cc++;
            if(a[j] == f[j])
                cf++;
        }
        if(cc == 6)
            n--;
 
        if(cf == 6)
            n++;
 
        cc = 0;
        cf = 0;
    }
 
    printf("%d\n",n);
 
    return 0;
}