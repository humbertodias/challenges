#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <string>  
#include <map>  
#include <stack>  
#include <vector>  
#include <set>  
#include <queue>  
#define maxn 205  
#define MAXN 200005  
#define INF 0x3f3f3f3f  
#define mod 1000000007  
#define eps 1e-6  
typedef long long ll;  
using namespace std;  
  
int n,m,ans,tot;  
int a[maxn],c[maxn],len[maxn],pos[maxn],last[maxn];  
int dp[205][205][205],num[maxn][maxn];  
  
void solve()  
{  
    int i,j,k,p;  
    memset(pos,0,sizeof(pos));  
    for(i=1;i<=tot;i++)  
    {  
        last[i]=pos[c[i]];  
        pos[c[i]]=i;  
    }  
    memset(num,0,sizeof(num));  
    for(i=tot;i>=1;i--)  
    {  
        for(j=1;j<=n;j++)  
        {  
            if(j==c[i]) num[j][i]=num[j][i+1]+len[i];  
            else num[j][i]=num[j][i+1];  
        }  
    }  
    memset(dp,0,sizeof(dp));  
    for(int l=1;l<=tot;l++)  
    {  
        for(i=1;i<=tot;i++)  
        {  
            j=i+l-1;  
            if(j>tot) break ;  
            for(k=0;k<=num[c[j]][j+1];k++)  
            {  
               dp[i][j][k]=dp[i][j-1][0]+(len[j]+k)*(len[j]+k);  
               for(p=last[j];p>=i;p=last[p])  
               {  
                   dp[i][j][k]=max(dp[i][j][k],dp[i][p][len[j]+k]+dp[p+1][j-1][0]);  
               }  
            }  
        }  
    }  
    ans=dp[1][tot][0];  
}  
int main()  
{  
    int i,test,ca=0;  
    scanf("%d",&test);  
    while(test--)  
    {  
        scanf("%d",&n);  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        tot=0;  
        memset(len,0,sizeof(len));  
        for(i=1;i<=n;)  
        {  
            tot++;  
            c[tot]=a[i];  
            while(i<=n&&a[i]==c[tot]) i++,len[tot]++;  
        }  
        solve();  
        printf("Case %d: %d\n",++ca,ans);  
    }  
    return 0;  
}  