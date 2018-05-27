// Algorithm: straightforward
// Complexity: O(n)

#include <cstdio>
#include <cassert>

#define MAXN 50

int main() {
	int n, m[MAXN];
	while(scanf("%d",&n) == 1 && n > 0) {
		assert(n <= MAXN);
		long long moves = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d", &m[i]);
			assert(m[i] >= 0 && m[i] <= 1000);
			moves += (1LL<<i) * m[i];
		}
		printf("%lld\n", moves);
	}
	assert(n == 0);
	return 0;
}