#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

ll n;
ll diff[5000];
ll diff2[5000];
ll ans[5000];

void calc(int a, int b, int c, int start) {
  if (a < b) { swap(a, b); }
  if (a < c) { swap(a, c); }
  if (b < c) { swap(b, c); }
  if (c == 0) { return; }
  assert(c >= 0);
  // line
  if (b == 1) {
    diff[0] += a / n;
    diff[n] -= a / n;
    diff[start] += 1;
    diff[start + a % n] -= 1;
    return;
  }

  // rect
  if (c == 1) {
    if (a >= n) {
      diff[0] += a / n * b;
      diff[n] -= a / n * b;
      calc(a % n, b, c, start);
      return;
    }
    diff2[start] += 1;
    diff2[start + b] -= 1;
    diff2[start + a] -= 1;
    diff2[start + a + b] += 1;
    // REP(i, b) { calc(a, 1, 1, (start + i) % n); }
    return;
  }

  // box
  if (a >= n) {
    diff[0] += a / n * b * c;
    diff[n] -= a / n * b * c;
    calc(a % n, b, c, start);
    return;
  }
  REP(i, c) {
    calc(a, b, 1, (start + i) % n);
  }
}

int main() {
  ll x, y, z, a, b, c;
  while (scanf("%lld %lld %lld %lld %lld %lld %lld", &x, &y, &z, &a, &b, &c, &n) > 0) {
    MEMSET(diff, 0);
    MEMSET(diff2, 0);
    MEMSET(ans, 0);
    ll A[3] = { a, 1, x - a - 1 };
    ll B[3] = { b, 1, y - b - 1 };
    ll C[3] = { c, 1, z - c - 1 };
    REP(i, 3) REP(j, 3) REP(k, 3) {
      int color = (abs(i - 1) + abs(j - 1) + abs(k  - 1) + n * 10) % n;
      calc(A[i], B[j], C[k], color);
    }
    ll sum = 0;
    REP(i, n * 3) {
      sum += diff2[i];
      diff[i] += sum;
    }
    sum = 0;
    REP(i, n * 3) {
      sum += diff[i];
      ans[i % n] += sum;
    }
    REP(i, n) {
      if (i != 0) { printf(" "); }
      printf("%lld", ans[i]);
    }
    puts("");
  }
}
