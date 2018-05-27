#include <cstdio>
#include <cstdlib>
using namespace std;
 
int T,n,i,j,k;
int f[1005][2];
 
int main()
{
    f[0][0]=1;
    f[0][1]=1;
    for(i=1;i<=1000;++i)
    {
        if(i&1)k=0;else k=1;
        for(j=i;j<=1000;++j)
        f[j][0]=(f[j][0]+f[j-i][k])%1000000007,
        f[j][1]=(f[j][1]+f[j-i][!k])%1000000007;
    }
    scanf("%d",&T);
    long long sum = 0;
    for(;T;--T)
    {
        scanf("%d",&n);
        // printf("%d\n",f[n][1]);
        sum+=f[n][1];
    }
    printf("%lld\n", sum);
}

 