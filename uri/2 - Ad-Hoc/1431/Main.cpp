#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int K[100];
int al[200000];

#define INF 1000000000

int main() {
    int N;
    
    while (scanf("%d", &N) && N) {
        int K[N];
        int cur = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d", K+i);
            for (int j = 0; j < K[i]; j++) {
                scanf("%d", &al[cur+j]); 
            }
            sort(al+cur, al+cur+K[i]);
            cur += K[i];
        }
        
        int dif_min = INF;
        for (int T = 0; T <= 1000; T++) {
            int dif = 0;
            cur = 0;
            for (int i = 0; i < N; i++) {
                
                int cnt = al+cur+K[i] - lower_bound(al+cur, al+cur+K[i], T);
                dif += abs(K[i] - 2*cnt);
                cur += K[i];
            }
            
            if (dif < dif_min) dif_min = dif;
        }
        
        printf("%d\n", dif_min);
    }
    
    return 0;
}