#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
int n,m,F,i,j,k,a,b,c,aim,ll,rr,ans_Max,ans_Min;
int e[100005];
bool opt;
 
struct node
{
    int l,r,Min,Max;
}t[10000005];
int root[1000005],tot;
 
void C(int &p,int l,int r)
{
    if(!p)p=++tot;
    if(l==r)
    {
        if(opt)t[p].Max=t[p].Min=l;
        else t[p].Max=0,t[p].Min=n+n;
        return;
    }
    int mid=(l+r)>>1;
    if(aim<=mid)C(t[p].l,l,mid);
    else C(t[p].r,mid+1,r);
    t[p].Max=0;t[p].Min=n+n;
    if(t[p].l)
    {
        if(t[t[p].l].Max>t[p].Max)t[p].Max=t[t[p].l].Max;
        if(t[t[p].l].Min<t[p].Min)t[p].Min=t[t[p].l].Min;
    }if(t[p].r)
    {
        if(t[t[p].r].Max>t[p].Max)t[p].Max=t[t[p].r].Max;
        if(t[t[p].r].Min<t[p].Min)t[p].Min=t[t[p].r].Min;
    }
}
 
void Q(int p,int l,int r)
{
    if(!p)return;
    if(l>=ll&&r<=rr)
    {
        if(t[p].Max>ans_Max)ans_Max=t[p].Max;
        if(t[p].Min<ans_Min)ans_Min=t[p].Min;
        return;
    }
    int mid=(l+r)>>1;
    if(rr<=mid)Q(t[p].l,l,mid);
    else if(ll>mid)Q(t[p].r,mid+1,r);
        else Q(t[p].l,l,mid),Q(t[p].r,mid+1,r);
}
 
int main()
{
    scanf("%d%d",&n,&F);
    scanf("%d%d%d",&a,&b,&c);
    e[1]=a;
    for(i=2;i<=n;++i)e[i]=((long long)e[i-1]*b+c)%F;
    for(i=1;i<=n;++i)
    {
        opt=true;
        aim=i;C(root[e[i]],1,n+n);
        aim=i+n;C(root[e[i]],1,n+n);
    }
    scanf("%d",&m);
    for(;m;--m)
    {
        scanf("%d",&i);
        opt=false;
        aim=i;C(root[e[i]],1,n+n);
        aim=i+n;C(root[e[i]],1,n+n);
        scanf("%d",&e[i]);
        opt=true;
        aim=i;C(root[e[i]],1,n+n);
        aim=i+n;C(root[e[i]],1,n+n);
        ll=i+1;rr=i+n-1;
        ans_Max=i;ans_Min=i+n;
        Q(root[e[i]],1,n+n);
        printf("%d %d\n",i+n-ans_Max,ans_Min-i);
    }
}