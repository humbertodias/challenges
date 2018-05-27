// Algorithm: euclidean algorithm
// Complexity: O(n*m)

#include <cstdio>
#include <cassert>

int a[10000];

int gcd(int a, int b) {
    return b?gcd(b, a%b) : a;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
        int total = 0;
        for (int i=0; i<n; ++i) {
            for (int j=1; j<m; ++j)
                scanf("%*d");
            scanf("%d", &a[i]);
            assert(a[i] >= 0 && a[i] <= 1000000000);
            assert(total <= 1000000000 - a[i]);
            total += a[i];
        }
        for (int i=0; i<n; ++i) {
            int t = gcd(a[i], total);
            printf("%d / %d\n", a[i] / t, total / t);
        }
    }
    assert(n == 0 && m == 0);
    return 0;
}