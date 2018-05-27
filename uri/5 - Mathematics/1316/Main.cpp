#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 1005;
const int N = 2005;
int m, l, n;
int box[N];

int total;

int dp[M];
bool path[N][M];
int result[N];

void knapsack()
{
    memset(dp, 0, sizeof(dp));
    memset(path, false, sizeof(path));
    for(int b = 1; b <= n; ++b) for(int c = m; c >= box[b]; --c)
            if(dp[c] >= dp[c-box[b]] + box[b])
            {
                path[b][c] = false;
            }
            else
            {
                dp[c] = dp[c-box[b]] + box[b];
                path[b][c] = true;
            }
}


void init()
{
    scanf("%d", &n);
    total = 0;
    for(int i = 1; i <= n; ++i) 
    { 
        scanf("%d", &box[i]); 
        total += box[i]; 
    } 
} 

void solve() 
{ 
    if(total > m+l)
    {
        printf("Impossible to distribute\n");
        return;
    }
    if(m >= total)
    {
        printf("%d ", n);
        for(int i = 1; i <= n; ++i) 
            printf("%d ", i); 
        printf("\n"); 
        return; 
    } 
    if(l >= total)
    {
        printf("0 \n");//must have trailing blank
        return;
    }
    knapsack();
    if(total-dp[m] <= l) 
    { 
        int t = 0; 
        int b = n, cap = m; 
        while(b > 0)
        {
            if(path[b][cap])
            {
                result[t++] = b;
                cap -= box[b];
            }
            --b;
        }
        printf("%d ", t);
        for(int i = t-1; i >= 0; --i)
            printf("%d ", result[i]);
        printf("\n");
    }
    else
        printf("Impossible to distribute\n");
}

int main()
{
    while(scanf("%d%d", &m, &l) && !(m==0&&l==0))
    {
        init();
        solve();
    }
    return 0;
}