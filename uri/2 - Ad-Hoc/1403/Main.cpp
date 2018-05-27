#include <cstdio>
#include <cstring>

int	vector [10009];

int main()
{
	int	i, j, x, p, s, N, M;

	while (scanf("%d %d", &N, &M) && (N || M)) {
		memset(vector, 0, sizeof vector);
		s = p = 0;

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				scanf("%d", &x);
				vector[x]++;
			}
		}
		for (i = 0; i <= 10000; i++) {
			if (vector[i] > p) {
				s = p;
				p = vector[i];
			} else {
				if (vector[i] > s)
					s = vector[i];
			}
		}

		for (i = 0; i <= 10000; i++) {
			if (vector[i] == s)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}