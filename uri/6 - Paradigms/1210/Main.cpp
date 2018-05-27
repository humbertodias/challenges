#include <cstdio>
#include <cstdlib>

int main(void)
{
	int	N, I, M, P, C[2000], V[2001], **S, **T, i, j, v1, v2, flag;
	while (scanf("%d %d %d %d", &N, &I, &M, &P) != EOF) {
		for (i = 0; i < M; i++)
			scanf("%d", &C[i]);
		for (i = 1; i <= M; i++)
			scanf("%d", &V[i]);
		S = (int **)malloc((N + 2) * sizeof(int *));
		for (i = 1; i <= N + 1; i++)
			S[i] = (int *)malloc((M + 1) * sizeof(int));
		T = (int **)malloc((N + 2) * sizeof(int *));
		for (i = 1; i <= N + 1; i++)
			T[i] = (int *)malloc((M + 1) * sizeof(int));
		for (j = 0; j <= M; j++)
			S[N + 1][j] = 0;
		for (i = N; i >= 1; i--) {
			for (j = 0; j < M; j++) {
				v1 = P + C[0] - V[j] + S[i + 1][1];
				v2 = C[j] + S[i + 1][j + 1];
				if (v1 <= v2) {
					S[i][j] = v1;
					T[i][j] = 1;
				} else {
					S[i][j] = v2;
					T[i][j] = 0;
				}
			}

			/* caso j = M */
			v1 = P + C[0] - V[j] + S[i + 1][1];
			S[i][j] = v1;
			T[i][j] = 1;
		}
		printf("%d\n", S[1][I]);
		flag = 1;
		for (i = 1, j = I; i <= N; i++) {
			if (T[i][j] == 1) {
				if (!flag)
					printf(" ");
				flag = 0;
				printf("%d", i);
				j = 1;
			} else
				j++;
		}
		if (flag)
			printf("0");
		printf("\n");
		for (i = 1; i <= N + 1; i++)
			free(S[i]);
		free(S);
		for (i = 1; i <= N + 1; i++)
			free(T[i]);
		free(T);
	}
	return 0;
}
