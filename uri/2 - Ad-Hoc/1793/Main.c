#include <stdio.h>

int min(int a, int b){
	return a<b?a:b;
}

int main(int argc, char const *argv[])
{
	int n, b, r, t, i;

	while(scanf("%d", &n) != EOF && n)
	{
		b = -1000, r = 10;

		for (i = 0; i < n; ++i)
		{
			scanf("%d", &t);
			if(i) r += (int) min(t - b, 10);
			b = t;
		}

		printf("%d\n", r);
	}

	return 0;
}