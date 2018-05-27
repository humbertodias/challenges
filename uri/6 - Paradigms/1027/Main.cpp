#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Pt {
    int x, y;
    Pt(int a=0, int b=0) :
        x(a), y(b) {}
    bool operator<(const Pt &a) const {
        if(a.x != x)
            return x < a.x;
        return y < a.y;        
    }
};
int main() {
    int n;
    int i, j;
    Pt D[1005];
    while(scanf("%d", &n) == 1) {
        for(i = 0; i < n; i++)
            scanf("%d %d", &D[i].x, &D[i].y);
        sort(D, D+n);
        int ret = 0;
        int dp[1005][2];
        for(i = 0; i < n; i++) {
            dp[i][0] = dp[i][1] = 1;
            for(j = i-1; j >= 0; j--) {
                if(D[i].x == D[j].x)
                    continue;
                if(D[i].y == D[j].y+2)
                    dp[i][0] = max(dp[i][0], dp[j][1]+1);
                if(D[i].y == D[j].y-2)
                    dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }
            ret = max(ret, dp[i][0]);
            ret = max(ret, dp[i][1]);
        }
        printf("%d\n", ret);
    }
    return 0;
} 