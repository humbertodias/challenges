#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
int n,m,i,j,k,ans,num;
long long a[1005],b[1005],tmp;
bool app[1005];
 
struct node
{
    long long a,b;
    int c;
}t[1000005];
 
long long gcd(long long a,long long b){if(!b)return a;return gcd(b,a%b);}
inline bool cmp(const node &a,const node &b)
{
    if(a.a!=b.a)return a.a<b.a;
    if(a.b!=b.b)return a.b<b.b;
    return a.c<b.c;
}
 
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lld %lld",&a[i],&b[i]);
    for(i=1;i<=n;++i)
    for(j=i+1;j<=n;++j)
    if(b[i]!=b[j])
    {
        ++m;
        t[m].a=a[i]*(b[i]-b[j])-b[i]*(a[i]-a[j]);
        t[m].b=b[i]-b[j];
        tmp=gcd(t[m].a,t[m].b);
        t[m].a/=tmp;
        t[m].b/=tmp;
        if(t[m].b<0)t[m].b=-t[m].b,t[m].a=-t[m].a;
        if(b[i]>b[j])t[m].c=i;else t[m].c=j;
    }
    sort(t+1,t+m+1,cmp);
    num=0;
    for(i=1;i<=m;++i)
    if(i==1||t[i].a!=t[i-1].a||t[i].b!=t[i-1].b)
    {
        if(!app[num])++ans,app[num]=true;
        num=1;
    }else
    {
        if(t[i].c!=t[i-1].c)++num;
    }
    if(!app[num])++ans;
    printf("%d\n",ans);
}