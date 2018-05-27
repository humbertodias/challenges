#include <iostream>

using namespace std;

int main () {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d", abs(j-i)+1);
                if (j != n-1) printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}