#include <cstdio>
#include <set>

#define ll long long int
#define MAX 100100
#define INF 1 << 30
#define GC getchar_unlocked()
 
using namespace std;
 
typedef pair<int, int> ii;
 
int N, M, X = 3, P = 3;
 
bool Read(int *N) {
    char ch;
    while ((ch = GC) < '-');
    for (*N = ch - '0'; (ch = GC) >= '0'; *N = ((*N * 5) << 1) + ch - '0');
    return true;
}
 
int main(void) {
 
    ii *D = new ii[MAX];
 
    D[1] = ii(1, 0);
    D[2] = ii(1, 1);
 
    for (int i = 3; i <= 100000;) {
        D[i++] = ii(P, 0);
        for (int j = 1; j < X; j++) {
            D[i++] = ii(P, j);
        }
        P += X, X++;
    }
    while (Read(&N), N) {
        printf("%d %d\n", D[N].first, D[N].second);
    }
    return 0;
    
}