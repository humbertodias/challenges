#include <cstdio>

using namespace std;
int main()
{
while(1)
{
 int n,m;
 scanf("%d %d",&n,&m);
 if(n==-1)break;
 long long ans=0,z;
 int i,temp=n;
 for(i=0;i<n;i++)
   {
    scanf("%lld",&z);
    ans+=(z*m*temp);
    temp--;
    }
 printf("%lld\n",ans);
}
return 0;
}