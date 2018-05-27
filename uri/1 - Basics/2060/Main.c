#include <stdio.h>
int 
main()
{
	int	i , n, a, b, c, d;
	a = 0, b = 0, c = 0, d = 0;
	scanf("%d", &n);
	int	e;
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		if (e % 2 == 0)
			a++;
		if (e % 3 == 0)
			b++;
		if (e % 4 == 0)
			c++;
		if (e % 5 == 0)
			d++;

	}

	printf("%d Multiplo(s) de 2\n", a);
	printf("%d Multiplo(s) de 3\n", b);
	printf("%d Multiplo(s) de 4\n", c);
	printf("%d Multiplo(s) de 5\n", d);
	return 0;
}