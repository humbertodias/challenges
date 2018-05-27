#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define DIGITS 4
#define LASTDIG DIGITS-1
#define BASE 1000000000000000000ULL // 10^18

int N,K;

class bigint {
    public:
    unsigned long long dig[DIGITS];
    
    bigint() {memset(dig,0,sizeof(dig));}
    bigint(unsigned long long int l) { memset(dig,0,sizeof(dig)); dig[0]=l; }
    
    bigint operator+ (bigint& ot) const {
        bigint n (*this);
        n += ot;
        return n;
    }
    
    bigint operator+= (const bigint& ot) {
        for (int i = 0; i < DIGITS; i++) {
            dig[i] += ot.dig[i];
            if (dig[i] >= BASE) {
                dig[i]-=BASE;
                dig[i+1]++;
            }
        }
        return -1;
    }
    
    bigint operator= (unsigned long long l) {
        memset(dig,0,sizeof(dig));
        dig[0]=l;
        return -1;
    }
    
    void print() {
        int i = LASTDIG;
        while (dig[i] == 0 && i > 0) i--;
        printf("%llu",dig[i]); i--;
        
        for (int j = i; j >=0; j--) printf("%018llu",dig[j]);
    }
};

int cont = 1;
int filled[110][8200];
bigint pd[110][8200];
int cnt;

void calc(int n, int mask) {
    //printf("calc %d %d %d\n", n, mask, cnt);
    //printf("calc %d %d\n", n, mask);
    cnt++;
    filled[n][mask] = cont;
    if (n == N) {
        pd[n][mask]=1;
        return;
    }
    
    //if (filled[n][mask] == cont) return;
    
    int append = (N-n > K);
    
    if (mask & (1 << (2*K)) ) {
        int nm = (mask^(1 << (2*K)))<<1;
        
        if (filled[n+1][nm+append] != cont) calc(n+1, nm + append);
        
        pd[n][mask] = pd[n+1][nm+append];
        return;
    }
    
    int m = mask;
    
    bigint resp;
    while (m) {
        int bit = m&-m;
        //printf("vo chama calc %d %d %d %d\n", mask, bit, append, ((mask^bit)<<1) + append);
        
        if (filled[n+1][((mask^bit)<<1) + append] != cont) calc(n+1, ((mask^bit)<<1) + append);
        resp += pd[n+1][((mask^bit)<<1) + append];
        m -= m&-m;
    }
    
    pd[n][mask] = resp;
}

int t;

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d %d", &N, &K);
        cont++;
        
        cnt = 0;
        int num = min(K+1, N);
        calc(1, (1<<num)-1);
        //printf("cnt=%d\n");
        pd[1][(1<<num)-1].print();
        printf("\n");
    }
}