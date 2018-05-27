// Solution: geometry, intervals
// Complexity: O(n^2)

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 1024
#define eps 1e-9

typedef vector<double> VD;

struct circle {
  int x, y, r, dist;
}c[MAXN];

int sqr(int a) {
  return a*a;
}

bool operator<(const circle &a, const circle &b) {
  return a.dist < b.dist;
}

double PI_2;

double adjust(double d) {
  d = fmod(d, PI_2);
  if (d < 0)
    d += PI_2;
  return d;
}

// determine if the interval [from, to] is covered by an interval in
// blocked_from, blocked_to or not
bool is_visible(VD &blocked_from, VD &blocked_to, double from, double to) {
  int j = 0, l = blocked_to.size();
  while(j < l && blocked_to[j]+eps < from)
    ++j;
  // now j >= l or blocked_to[j] >= from
  // check if view is blocked completely
  if (j < l && blocked_from[j] <= from+eps && blocked_to[j] >= to-eps)
    return false;
  // update blocked intervals
  int s = j;
  while(j < l && blocked_from[j]-eps <= to) {
    assert(blocked_to[j]+eps >= from);
    from = min(from, blocked_from[j]);
    to = max(to, blocked_to[j]);
    ++j;
  }
  blocked_from.insert(blocked_from.begin() + s, from);
  blocked_to.insert(blocked_to.begin() + s, to);
  if (s != j) {
    blocked_from.erase(blocked_from.begin() + s + 1, blocked_from.begin() + j + 1);
    blocked_to.erase(blocked_to.begin() + s + 1, blocked_to.begin() + j + 1);
  }
  return true;
}

int main() {
  int n;
  PI_2 = acos(0.0) * 4;
  while(scanf("%d", &n) == 1 && n) {
    assert(n > 0 && n <= 1000);
    for (int i=0; i<n; ++i) {
      assert( scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].r) == 3);
      assert(abs(c[i].x) <= 10000 && abs(c[i].y) <= 10000 && c[i].r > 0 && c[i].r <= 1000);
      c[i].dist = sqr(c[i].x) + sqr(c[i].y) - sqr(c[i].r);
    }
    sort(c, c + n);
    VD blocked_from, blocked_to;
    double best = 0;
    for (int i=0; i<n; ++i) {
      double dist = sqrt(sqr(c[i].x)+sqr(c[i].y));

      // some validity checks
      assert(dist > c[i].r);
      for (int j=0; j<i; ++j)
        assert(sqrt(sqr(c[i].x-c[j].x)+sqr(c[i].y-c[j].y))>c[i].r+c[j].r);

      double phi = atan2(c[i].y, c[i].x);
      double phi2 = asin(c[i].r / dist);
      double from = adjust(phi - phi2);
      double to = adjust(phi + phi2);
      if (to < from) {
        // in this case, split the interval in two parts
        // and check them individually
        bool visible = is_visible(blocked_from, blocked_to, from, PI_2);
        // call is_visible again (is necessary, even if visible is
        // already set to true (function modifies blocked_from, blocked_to)
        if (is_visible(blocked_from, blocked_to, 0, to))
          visible = true;
        if (visible)
          best = max(best, dist - c[i].r);
      }
      else if (is_visible(blocked_from, blocked_to, from, to))
        best = max(best, dist - c[i].r);
    }
    printf("%.3lf\n", best);
  }
  assert(n == 0);
  return 0;
}