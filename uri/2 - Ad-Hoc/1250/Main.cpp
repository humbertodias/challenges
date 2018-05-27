#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

#define MIN(a, b) ((a) < (b) ?  (a) : (b))
#define MAX(a, b) ((a) > (b) ?  (a) : (b))
#define ABS(a)    ((a) <  0  ? -(a) : (a))
#define IMPAR(a)  ((a)&1)
#define CTOI(a)   ((a) - '0')
#define ITOC(a)   ((a) + '0')

#define TRUE  1
#define FALSE 0

int main()
{
  int N, T, i, hit, tiros[50];
  char acoes[51];
  
  scanf("%d", &N);
  
  while(N--)
  {
    scanf("%d", &T);
    
    for(i = 0; i < T; i++)
      scanf("%d", &tiros[i]);
    
    scanf(" %s", acoes);
    
    for(i = 0, hit = 0; i < T; i++)
      if((acoes[i] == 'S' && tiros[i] < 3) || (acoes[i] == 'J' && tiros[i] > 2))
        hit++;
    
    printf("%d\n", hit);
  }
  
  return 0;
}