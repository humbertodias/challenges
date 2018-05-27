#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
 
#define INF 0x3f3f3f3ff

int n;
double dist[17][17], memo[17][1<<17];

double d(int x1, int y1, int x2, int y2){
    return hypot(x1-x2, y1-y2);
}

double solve(int id, int bitmask){
    if(__builtin_popcount(bitmask)==n)
        return dist[id][0];
    if(memo[id][bitmask] != -1)
        return memo[id][bitmask];

    double ans = INF;
    for(int i=0; i<n; i++)
        if(!(bitmask & (1 << i)))
            ans = min(ans, dist[id][i] + solve(i, bitmask | (1<<i)));

    return memo[id][bitmask] = ans;
}

int main(){
    while(scanf("%d", &n), n){
        n++;
        int x[n], y[n];
        for(int i=0; i<n; i++)
            scanf("%d %d", x+i, y+i);

        for( int i=0; i<n; i++)
            for(int j=i; j< n; j++)
                dist[i][j] = dist[j][i] = d(x[i], y[i], x[j], y[j]);

        for(int i=0; i<n; i++)
            for(int j=0; j< (1 << n); j++)
                memo[i][j] = -1;

        printf("%.2f\n", solve(0,1));            

    }
}