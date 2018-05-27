#include <cstdio>
#include <algorithm>

using namespace std;

int S, B;

#define INF 1000000000

int pd[250][151][250];

int roleta[300];
int soma[600];
int bola[300];

int main() {
    for (int i = 0; i < 250; i++) 
        for (int j = 0; j < S; i++) 
            pd[i][0][j] = 0;
    
    while (scanf("%d %d", &S, &B) && S) {
        for (int i = 0; i < S; i++) scanf("%d", roleta+i);
        for (int i = 1; i <= B; i++) scanf("%d", bola+i);
        
        for (int i = 0; i < S; i++) soma[i] = roleta[i] + roleta[(i+1)%S];
        for (int i = S; i < 2*S; i++) soma[i] = soma[i%S];
        
        int res = INF;
        for (int st = 0; st < S; st++) {
            for (int b = 1; b <= B; b++) {
                for (int ult = 2*b-2; ult < S-1; ult++) {
                    pd[st][b][ult] = pd[st][b-1][ult-2] + bola[b]*(soma[st+ult]);
                    if (ult != 2*b-2) pd[st][b][ult] = min(pd[st][b][ult], pd[st][b][ult-1]);
                }
            }
            res = min(res, pd[st][B][S-2]);
        }
        
        printf("%d\n",-res);
    }
}