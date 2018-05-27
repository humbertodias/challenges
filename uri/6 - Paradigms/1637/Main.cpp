// Algorithm: Dynamic Programming
// Complexity: O(n^3)

#include <cstdio>
#include <cstring>
#include <climits>
#include <cassert>
#include <algorithm>
using namespace std;

#define MAXN 128

int c[MAXN];
int dp[MAXN+1][MAXN+1];

int main() {
  int n;
  while(scanf("%d", &n) == 1 && n) {
    assert(n > 0 && n <= MAXN);
    for (int i=0; i<n; ++i) {
      scanf("%d", &c[i]);
      assert(c[i] >= 0 && c[i] <= 100000);
    }
    for (int i=0; i<n; ++i) {
      int sum = 0;
      for (int j=0; j<=i+1; ++j)
        dp[i+1][j] = INT_MAX;
      for (int j=i; j>=0; --j) {
        sum += c[j];
        for (int k=(j?1:0); k<=j; ++k)
          dp[i+1][k+1] = min(dp[i+1][k+1], dp[j][k] + sum * (k+i+2));
      }
    }
    int opt = INT_MAX;
    for (int i=1; i<=n; ++i)
      opt = min(opt, dp[n][i]);
    printf("%d\n", opt);
  }
  return 0;
}