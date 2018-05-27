/*
lemma: for at least one person, the food portion size x must be chosen in such a way that there is no excess food,
i. e. y_i / x is an integer
proof: Assume there is an optimal solution without this property. We will show how to improve this solution.
For each person, determine how often he goes to fetch food, and determine average remainder of food per time.
If we take the minimum such average, decreasing the food portion size by this amount does not change the
number of times the persons go to fetch food. However, the excess food will be decreased, therefore the overall
costs are decreased, therefore the solution was not optimal.
*/

// Algorithm: brute force
// Complexity: O(n^2)

#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define MAXN 1000
#define MAXFETCH 3

int y[MAXN];

int main() {
    int a, b, n;
    while(scanf("%d", &n) == 1 && n) {
        assert(n > 0 && n <= MAXN);
        scanf("%d %d", &a, &b);
        assert(a > 0 && a <= 10 && b > 0 && b <= 10);
        for (int i=0; i<n; ++i) {
            scanf("%d", &y[i]);
            assert(y[i] > 0 && y[i] <= 100);
        }
        sort(y, y+n);
        int bestCostNum = 100000000, bestCostDenom = 1;
        int bi, bj;
        for (int i=0; i<n; ++i) {
            if (i && y[i] == y[i-1])
                continue;
            for (int j=1; j<=MAXFETCH; ++j) {
                int cost = 0;
                // food portion size: y[i] / j
                // check if it is large enough
                if (y[n-1] * j > MAXFETCH * y[i])
                    continue;
                for (int k=0; k<n; ++k) {
                    // determine number of times to fetch food
                    int fetches = (y[k] * j + y[i]-1) / y[i];
                    assert(fetches <= MAXFETCH);
                    // determine amount of excess food
                    cost += a * (fetches * y[i] - y[k] * j) + b * fetches * j;
                }
                if (cost * bestCostDenom < bestCostNum * j) {
                    bestCostNum = cost;
                    bestCostDenom = j;
                    bi = i;
                    bj = j;
                }
            }
        }
        if (bestCostNum % bestCostDenom == 0)
            printf("%d\n", bestCostNum / bestCostDenom);
        else
            printf("%d / %d\n", bestCostNum, bestCostDenom);
    }
    return 0;
}