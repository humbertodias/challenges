#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

#define MIN(a, b)   ((a) < (b) ?  (a) : (b))
#define MAX(a, b)   ((a) > (b) ?  (a) : (b))
#define ABS(a)      ((a) <  0  ? -(a) : (a))
#define IMPAR(a)    ((a)&1)
#define CTOI(a)     ((a) - '0')
#define ITOC(a)     ((a) + '0')

#define TRUE    1
#define FALSE   0

int main()
{
    int N, K, i, d;
    char idiomas[100][21];

    scanf("%d", &N);
    
    while(N--)
    {
        scanf("%d", &K);
        
        for(i = 0; i < K; i++)
            scanf(" %s", idiomas[i]);
        
        d = 0;
        
        for(i = 1; i < K && !d; i++)
            if(strcmp(idiomas[0], idiomas[i]) != 0)
                d = 1;
        
        if(d)
            printf("ingles\n");
        else
            printf("%s\n", idiomas[0]);
        
    }

    
    return 0;
}