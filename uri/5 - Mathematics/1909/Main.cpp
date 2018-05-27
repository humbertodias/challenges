#include <stdio.h>
 
long long t, q[100], mmc, n;

long long MDC(long long a, long long b)
{
    if(b == 0)
        return a;
    else 
        return MDC(b, a%b);
}
long long MMC(long long a, long long b)
{
    if(a == 0 || b == 0)
        return 0;
    return (a*b)/MDC(a,b);
}
int checa(int x)
{
    for(int i=0; i<n; i++)
    {
        if(q[i]==x)
            return 0;
    }
    return 1;
}
long long novaBola()
{
    int i;
    for(i=2; i<=t; i++)
    {
        if(t%i == 0)
            if(MMC(i,mmc) == t)
                if(checa(i))   
                    return i;
    }
    return -1;
}
int main()
{       
     
    scanf("%lld %lld", &n, &t);
    while(n>0 || t>0)
    {
        for(int i=0; i<n; i++)
            scanf("%lld", &q[i]);
         
            mmc=1;
            for(int i=0; i<n; i++)
            {
                mmc = MMC(mmc, q[i]);
            }
            mmc = novaBola();
            if(mmc>1)
                printf("%lld\n", mmc);
            else
                printf("impossivel\n");
 
        scanf("%lld %lld", &n, &t);
    }
}