#include <cstdio>

#define MAXN 100000

int a[MAXN], ind[MAXN];

int main() {
	int c, n;
	while(scanf("%d %d",&c,&n) == 2 && (n || c)) {
		for (int i=0; i<c; ++i)
			ind[i] = -1;
		for (int i=0; i<n; ++i) {
			scanf("%d",&a[i]);
		}
		int sum = 0;
		ind[0] = 0;
		bool found = false;
		for (int i=0; i<n; ++i) {
			sum = (sum + a[i]) % c;
			if (ind[sum] >= 0) {
				int checksum = 0;
				for (int j=ind[sum]; j<=i; ++j) {
					checksum = (checksum+a[j])%c;
					printf("%d",j+1);
					if (j < i) printf(" ");
					else puts("");
				}
				found = true;
				break;
			}
			ind[sum] = i+1;
		}
	}
	return 0;
}
