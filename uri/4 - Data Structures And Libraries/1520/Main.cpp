#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>

#define MIN(a, b)   ((a) < (b) ?  (a) : (b))
#define MAX(a, b)   ((a) > (b) ?  (a) : (b))
#define ABS(a)      ((a) <  0  ? -(a) : (a))
#define IMPAR(a)    ((a)&1)
#define CTOI(a)     ((a) - '0')
#define ITOC(a)     ((a) + '0')

#define TRUE    1
#define FALSE   0

int ordena(const void *arg1, const void *arg2)
{
    int *i = (int *) arg1, *j = (int *) arg2;
    
    if(*i == *j)
        return 0;
    else if(*i > *j)
        return 1;
    else
        return -1;
}

int main()
{
    int N, X, Y, rack[10000], i, j, pos, inicio, *res;
    
    while(scanf("%d", &N) != EOF)
    {
        for(i = 0, pos = 0; i < N; i++)
        {
            scanf("%d %d", &X, &Y);
            
            for(j = X; j <= Y; j++)
                rack[pos++] = j;
        }
        
        qsort(rack, pos, sizeof(int), ordena);
        
        scanf("%d", &N);
        
        res = (int *) bsearch(&N, rack, pos, sizeof(int), ordena);
        
        if(res)
        {
            for(inicio = res - rack; rack[inicio - 1] == N && inicio > 0; inicio--);
            for(i = inicio; i < pos && rack[i] == N; i++);
            
            printf("%d found from %d to %d\n", N, inicio, i - 1);
        }
        else
            printf("%d not found\n", N);
    }
    
    return 0;
}