#include<cstdio>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

const int MAXN=1100;
int p[MAXN],d[MAXN],cot[2][MAXN];

int findp(int x) {
    if(p[x]==-1) {
        return x;
    }
    int ret=findp(p[x]);
    d[x]=(d[x]+d[p[x]])&1;
    return p[x]=ret;
}

int main() {
    int n;
    while(scanf("%d",&n),n) {
        memset(p,-1,sizeof(p));
        memset(d,0,sizeof(d));
        bool flg=true;
        for(int x=0; x<n; x++) {
            int y;
            char s[100];
            scanf("%s%d%s%s",s,&y,s,s);
            y--;
            int px=findp(x);
            int py=findp(y);
            int ret;
            if(s[0]=='t') {
                ret=0;
            } else {
                ret=1;
            }
            if(px!=py) {
                d[py]=(d[x]+d[y]+ret)&1;
                p[py]=px;
            } else {
                if(((d[x]+d[y])&1)!=ret) {
                    flg=false;
                }
            }
        }
        if(!flg) {
            puts("Inconsistent");
        } else {
            int ans=0;
            memset(cot,0,sizeof(cot));
            for(int i=0; i<n; i++) {
                int px=findp(i);
                cot[d[i]&1][px]++;
            }
            for(int i=0; i<n; i++) {
                ans+=max(cot[0][i],cot[1][i]);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}