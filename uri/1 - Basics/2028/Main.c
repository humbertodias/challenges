#include<stdio.h>

int main()
{
    int i, k, sum,n, TC=0;

    while(scanf("%d", &n) != EOF)
    {
        TC++;
        sum=0;
        if(n==0)
        {
            sum++;
            printf("Caso %d: %d numero\n", TC,sum);
            printf("0\n");
        }
        else
        {
            for(i=0; i<=n; i++)
            {
                for(k=1; k<=i; k++)
                {
                    sum++;
                }
            }
            printf("Caso %d: %d numeros\n", TC, sum+1);
            printf("0 ");
            for(i=0; i<=n; i++)
            {
                for(k=1; k<=i; k++)
                {
                    printf("%d", i);
                    if(k<n) printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}