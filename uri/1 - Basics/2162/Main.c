#include <stdio.h>
#define QTD 100
 
int main(void) {
int n, h[QTD],i,j,sentido,sentidoFI,pico;
 
    //j = 2;
    pico = 1;
 
    do
    {
 
        scanf("%d",&n);

        for ( i = 0; i < n; i++)
        {
            scanf("%d",&h[i]);
        }
 
        if (h[0] > h[1])//começa descendo
        {
            sentido = 0;//sempre que sentido = 0, o valor esta decrescendo
        }
 
 
        else//começa subindo
        {
            sentido = 1;//sempre que sentido = 1, o valor esta crescendo
        }
 
 
            for (i = 1; i < n; i++)
            {
                if (sentido == 0 && i != n - 1)//descendo
                {
                    if (h[i] < h[i + 1])// se um valor for menor que o proximo, isto é um pico
                    {
                        sentido = 1;
                        pico++;
                    }
 
                    else
                    {
 
                        if (sentido == 1 && i != n - 1)//subindo
                        {
                            if (h[i] > h[i + 1])// se um valor for menor que o proximo, isto é um pico
                            {
                                sentido = 0;
                                pico++;
                            }
                        }
 
                    }
 
                }
 
                if (i == n - 1)
                {
                    if (h[n - 1] > h[0])
                    {
                        sentidoFI = 0;
                    }
 
                    else        
                    {
                        sentidoFI = 1;
                    }
 
 
                    if (sentido != sentidoFI)
                    {
                        pico++;
                    }
                }
            }
 
 
            printf("%d",pico);
 
    } while (n != 0);
 
    return 0;
}