#include <cstdio>
#include <cstdlib>
 
int C, N;
int P1[10][10], P2[10][10];
 
bool solve(int P[10][10]) {
    bool onlyOne = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (abs(P[i][j]) != 1)
                onlyOne = 0;
    if (onlyOne) {
        for (int i = 1; i <= N; i++) {
            int cntp = 0, cntn = 0;
            for (int j = 1; j <= N; j++) {
                if (P[i][j] == 1)
                    cntp++;
                else
                    cntn++;
            }
            if (cntp != N && cntp != cntn+1)
                return 0;
        }
        return 1;
    }
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = N; k > j; k--) {
                if (abs(P[i][k]) < abs(P[i][k-1])) {
                    for (int l = 1; l <= N; l++) {
                        int tmp = P[l][k];
                        P[l][k] = P[l][k-1];
                        P[l][k-1] = tmp;
                    }
                }
            }
        }
    }
 
    for (int i = 1; i <= N; i++) {
        if (P[i][1] != 1)
            return 0;
        for (int j = 3; j <= N; j++)
            if (P[i][j] != P[i][j-1] * P[i][2])
                return 0;
    }
    return 1;
}
 
int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &P1[i][j]);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                P2[j][i] = P1[i][j];
        puts(solve(P1) || solve(P2) ? "Potencia" : "Nao Potencia");
    }
}