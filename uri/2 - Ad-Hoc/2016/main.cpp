#include <cstdio>  

int main()  
{  
    int p, r, q;  
    scanf("%d%d", &p, &r);  
    q = p-1;  
    int ara[q], bnk, b, cnt=0, sum=0, i, j, nit;  
    for(i=1; i<=r; i++)  
    {  
        sum = 0;  
        scanf("%d", &bnk);  
        scanf("%d", &b);  
        for(j=0; j<q; j++)  
        {  
            scanf("%d", &ara[j]);  
            sum += ara[j];  
        }  
        if(sum>=bnk)  
            continue;  
        if(sum+b > bnk) b=0;  
        nit = bnk - sum;  
        if(bnk-sum>=10000) cnt += (10000 - b);  
        else if((bnk-sum)>=1000) cnt += (1000 - b);  
        else if((bnk-sum)>=100) cnt += (100 - b);  
        else if((bnk-sum)>=10) cnt += (10 - b);  
        else if((bnk-sum)>=1) cnt += (1- b);  
    }  
    printf("%d\n", cnt);  
    return 0;  
}  