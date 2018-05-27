#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
 
int T,n,m,i,j,k,shi,tot,sum;
int x[505],y[505];
double l,r,mid,a,d,pi,pi2,u,v;
 
struct node
{
    double x;
    int val;
}t[10005];
double Abs(double x){if(x<0)return -x;return x;}
double sqr(double x){return x*x;}
inline bool cmp(const node &a,const node &b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.val>b.val;
}
 
int main()
{
    pi=atan2(0,-1);pi2=2*pi;
    scanf("%d",&T);
    for(;T;--T)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
        l=0;r=200000;
        for(shi=50;shi;--shi)
        {
            mid=(l+r)/2;
            for(i=1;i<=n;++i)
            {
                tot=0;
                for(j=1;j<=n;++j)
                if(sqr(y[j]-y[i])+sqr(x[j]-x[i])<=sqr(2*mid))
                {
                    a=atan2(y[j]-y[i],x[j]-x[i]);
                    d=acos(sqrt(sqr(y[j]-y[i])+sqr(x[j]-x[i]))/2/mid);
                    u=a-d+pi;v=a+d+pi;
                    if(u<0)
                    {
                        ++tot;t[tot].x=u+pi2;t[tot].val=1;
                        ++tot;t[tot].x=pi2;t[tot].val=-1;
                        u=0;
                    }
                    if(v>pi2)
                    {
                        ++tot;t[tot].x=0;t[tot].val=1;
                        ++tot;t[tot].x=v-pi2;t[tot].val=-1;
                        v=pi2;
                    }
                    ++tot;t[tot].x=u;t[tot].val=1;
                    ++tot;t[tot].x=v;t[tot].val=-1;
                }
                sort(t+1,t+tot+1,cmp);
                sum=0;
                for(j=1;j<=tot;++j)
                {
                    sum+=t[j].val;
                    if(sum>=m)break;
                }
                if(sum>=m)break;
            }
            if(i<=n)r=mid;else l=mid;
        }
        printf("%.4lf\n",mid);
    }
}