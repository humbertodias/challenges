#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
int n,i,j,k,l,r,mid,ans;
int A[100005],B[100005];
 
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&A[i]);
    for(i=1;i<=n;++i)scanf("%d",&B[i]);
    sort(A+1,A+n+1);
    sort(B+1,B+n+1);
    l=0;r=n;
    while(l<=r)
    {
        mid=(l+r)>>1;
        for(i=1;i<=mid;++i)
        if(A[i]>=B[n-mid+i])
        break;
        if(i>mid)l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d\n",ans);
}