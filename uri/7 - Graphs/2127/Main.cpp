#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
 
int n, m;
int p[1005];
int r[1005];
int ans;
int a1[2000005], a2[2000005];
int b1[2000005], b2[2000005];
int c1[2000005], c2[2000005];
int sa, sb, sc;
int cnt;
 
int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
 
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  p[x] = y;
  return true;
}
 
int main() {
  srand((unsigned int)time(NULL));
  int test = 0;
  while (scanf("%d%d", &n, &m) != EOF) {
    test++;
    // if (test != 1) printf("\n");
    printf("Instancia %d\n", test);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      r[i] = 0;
    }
    sa = sb = sc = 0;
    for (int i = 0; i < m; i++) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      x--;
      y--;
      if (w == 1235) {
        a1[sa] = x;
        a2[sa] = y;
        sa++;
      } else if (w == 8977) {
        b1[sb] = x;
        b2[sb] = y;
        sb++;
      } else if (w == 10923) {
        c1[sc] = x;
        c2[sc] = y;
        sc++;
      }
    }
    ans = 0;
    cnt = n;
    for (int i = 0; i < sa /*&& cnt > 1*/; i++) {
      if (merge(a1[i], a2[i])) {
        ans += 1235;
        //cnt--;
      }
    }
    for (int i = 0; i < sb /*&& cnt > 1*/; i++) {
      if (merge(b1[i], b2[i])) {
        ans += 8977;
        //cnt--;
      }
    }
    for (int i = 0; i < sc /*&& cnt > 1*/; i++) {
      if (merge(c1[i], c2[i])) {
        ans += 10923;
        //cnt--;
      }
    }
    printf("%d\n\n", ans);
  }
}