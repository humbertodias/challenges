#include <cstdio>
#include <cstdlib>
using namespace std;
 
int n,i,j,k,Max1,Max2,a,sum;
 
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a);
        if(a>=Max1)Max2=Max1,Max1=a;
        else if(a>Max2)Max2=a;
        sum+=a;
    }
    if(Max1*100>=sum*45||(Max1*100>=sum*40&&(Max1-Max2)*10>=sum))
    printf("1\n");else printf("2\n");
}