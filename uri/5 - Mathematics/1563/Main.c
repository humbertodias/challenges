#include <stdio.h>
#include <math.h>
#include <stdio.h>

int main() {
    int n, l, c, e, f, t;
 
    while (scanf("%d", &n)) {
        if (n>=0 && n<=15) {
            if (n==0) break;
            e=1; f=1;
            t=pow(2,n)/2; t=t*t;
            for (l=1; l<=n; l++) {
                for (c=1; c<=n; c++) {
                    if (l==1 && c==1) e=1; else if (c>1) e=e+e;
                    if (t>99999999) printf("%9d", e);
                    else if (t>9999999) printf("%8d", e);
                    else if (t>999999) printf("%7d", e);
                    else if (t>99999) printf("%6d", e);
                    else if (t>9999) printf("%5d", e);
                    else if (t>999) printf("%4d", e);
                    else if (t>99) printf("%3d", e);
                    else if (t>9) printf("%2d", e);
                    else printf("%d", e);
                    if (c<n) printf(" ");
                }
                f=f+f; e=f;
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
