#include <cstdio>
#include <cstring>

long long count[60][100];

void pre() {
    memset(count,0,sizeof(count));
    
    long long c = 1;
    
    for (int i = 0; i < 30; i++) {
        count[2*i][0] = c;
        
        c *= (2*(2*i+1));
        c /= i+2;
    }
    
    for (int p = 1; p < 26; p++) {
        for (int i = 0; i <= 51; i++) {
            for (int k = 0; i-k-1 >= 0; k += 2) {
                count[i][p] += count[k][0] * count[i-k-1][p-1];
            }
        }
    }
}

void get(int n, long long k) {
    int p = 0;
    
    long long tot = (1LL << n) - count[n][p];
    if (k > tot) {
        printf("-1");
        return;
    }
    
    int ig = 0;
    while (n) {
        n--;
        long long malf;
        
        if (ig) malf = 1LL << n;
        else malf = (1LL << n) - count[n][p+1];
        
        if (malf >= k) {
            printf("("); p++;
        }
        else {
            printf(")"); p--;
            k -= malf;
            
            if (p < 0) ig = 1;
        }

    }
}

int main() {
    pre();
    
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int N;
        long long K;
        scanf("%d %lld", &N, &K);
        
        get(N,K+1);
        printf("\n");
    }
    
}