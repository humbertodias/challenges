#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int deg[100000];

int invcmp(int a, int b) {
    return b < a;
}

int main() {
    int H, R;
    
  while (scanf("%d %d", &H, &R) && H) {
        memset(deg, 0, sizeof(deg));
        
    for (int i = 0; i < R; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            deg[a]++;
            deg[b]++;
        }
    
    sort(deg+1, deg+H+1, invcmp);
    int sum = 0;
    int m;
    for (m = 1; m <= H && deg[m] >= m-1; m++) {
            sum += deg[m];
        }
        
        int s2 = 0;
        for (int i = m; i <= H; i++) {
            s2 += deg[i];
        }
        
    if (sum == (m-1)*(m-2) + s2) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}