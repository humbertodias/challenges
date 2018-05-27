#include <cstdio>

using namespace std;

int main() {
    long N, M, i, temp;
    int a2, a5, a, ans;

    while (scanf("%ld %ld", &N, &M) != EOF) {
        if (M == 0) {
            printf("1\n");
            continue;
        }

        a2 = 0; 
        a5 = 0; 
        ans = 1;
        for ( i = N - M + 1 ; i <= N ; i++) {
            temp = i;
            while(temp % 2 == 0) {
                temp /= 2;
                a2++;
            }
            while(temp % 5 == 0) {
                temp /= 5;
                a5++;
            }
            
            ans = (ans * (temp%10)) % 10;
        }
   
        if (a2 < a5) {
            a = a5 - a2;
            for (i = 0 ; i < a ; i++)
                ans = (ans * 5) % 10;
        }
        else {
            a = a2 - a5;
            for (i = 0 ; i < a ; i++)
                ans = (ans * 2) % 10;
        
        }

        printf("%d\n", ans);
    }

    return 0;
}