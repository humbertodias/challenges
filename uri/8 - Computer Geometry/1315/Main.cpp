#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 150;

struct Point{
  int x, y;
  bool operator<(const Point &a)const
  {
      return atan2(y + 0.0, x + 0.0) < atan2(a.y + 0.0 , a.x + 0.0);
  }
}p[maxn];
int B, N, area;
Point zero;
int dp[55][maxn][maxn];

int det(Point a, Point b, Point c){
   return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
}

int calc(int from, int to){
   int cnt = 0, area = 0;
   Point stack[maxn];
   for(int i = from; i < to; i++){
       while(cnt >= 2 && det(p[i % N], stack[cnt-1], stack[cnt-2]) > 0)cnt--;
       stack[cnt++] = p[i % N];
   }
   for(int i = 0; i < cnt-1; i++)
       area += det(stack[i], stack[i+1], zero);
   return area;
}

void solve(){
   area = -1;
   memset(dp, -1, sizeof(dp));
   for(int i = 0; i < N; i++)
       for(int j = 2; j <= N; j++){
          if(det(p[i], p[(i+j-1)%N], zero) < 0)break;
          dp[1][i][j] = calc(i, i + j);
          //cout<<i<<" "<<j<<" "<<dp[1][i][j]<<endl;
       }
       for(int k = 2; k <= B; k++){
          for(int i = 0; i < N; i++)
              for(int j = 2*k; j <= N; j++)
              {
                  for(int q = 2; q <= j - 2*(k-1); q++)
                  {
                      if(dp[k-1][(i+q)%N][j - q]==-1)continue;
                      if(dp[1][i][q]==-1)continue;
                      int t = dp[1][i][q] + dp[k-1][(i+q)%N][j - q];
                      if(t < dp[k][i][j] || dp[k][i][j]==-1)dp[k][i][j] = t;
                  }
              }
       }
       for(int i = 0; i < N; i++)
           if( dp[B][i][N]!=-1 && (dp[B][i][N] < area || area==-1) )
               area = dp[B][i][N];
}

int main(){
   zero.x = zero.y = 0;
   while(scanf("%d %d",&B, &N) &&(B + N)){
        int x0, y0;
        scanf("%d %d",&x0, &y0);
        for(int i = 0; i < N-1; i++){
            scanf("%d %d",&p[i].x, &p[i].y);
            p[i].x -= x0;
            p[i].y -= y0;
        }
        sort(p, p + (--N) );
        solve();
        printf("%.2lf\n",area * 0.5);
   }   
}