#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 17
typedef struct {
	int		c          [MAX];
}		poly;
poly 
poly_add(poly A, poly B)
{
	int		i;
	poly		R;
	for (i = 0; i < MAX; i++) {
		R.c[i] = A.c[i] + B.c[i];
	}
	return R;
}
poly 
poly_mul(poly A, poly B)
{
	int		i         , j, k;
	poly		R;
	memset(&R, 0, sizeof(R));
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			k = i - j;
			if (k < 0 || MAX <= k)
				continue;
			R.c[i] += A.c[j] * B.c[k];
		}
	}
	return R;
}
poly 
poly_read(char *p)
{
	char           *q;
	int		i         , d;
	poly		acc      , cur, tmp;
	memset(&acc, 0, sizeof(acc));
	memset(&cur, 0, sizeof(cur));
	cur.c[0] = 1;
	q = p;
	do {
		p++;
		if (!isdigit(*p)) {
			d = p - q;
			memset(&tmp, 0, sizeof(tmp));



			for (i = 0; i < d; i++) {
				tmp.c[i] = *(p - (i + 1)) - '0';
			}
			cur = poly_mul(cur, tmp);
			if (*p != '*') {
				acc = poly_add(acc, cur);
				memset(&cur, 0, sizeof(cur));
				cur.c[0] = 1;
			}
			q = p + 1;
		}
	} while (*p != '=' && *p != '\0');
	return acc;
}
int		div        [1920], ndiv;
int 
cmp_int(const void *p, const void *q)
{
	return *(int *)p - *(int *)q;
}
void 
find_div(int N)
{
	int		i         , p, old;
	if (N < 0)
		N = -N;
	ndiv = 0;
	div[ndiv++] = 1;
	for (p = 2; p <= 46337 && p * p <= N; p++) {
		old = ndiv;
		while (N % p == 0) {
			for (i = 0; i < old; i++) {
				div[ndiv] = div[ndiv - old] * p;
				ndiv++;
			}
			N /= p;
		}
	}
	if (N > 1) {
		old = ndiv;
		for (i = 0; i < old; i++) {
			div[ndiv] = div[ndiv - old] * N;
			ndiv++;
		}
	}
	qsort(div, ndiv, sizeof(int), cmp_int);
}
poly		lhs      , rhs;



int 
check(int x)
{
	int		acc       , i;
	acc = 0;
	for (i = 0; i < MAX; i++) {
		acc /= x;
		acc += lhs.c[i];
		if (acc % x != 0) {
			return 0;
		}
	}
	return (acc == 0);
}
int 
main()
{
	int		TC;
	int		h         , i, j, max, fail;
	char           *p;
	char		buf       [2 * MAX + 2];
	for (;;) {
		gets(buf);
		if (buf[0] == '=') {
			break;
		}
		max = 1;
		for (p = buf; *p; p++) {
			if (*p == '=') {
				continue;
			}
			if (*p - '0' > max) {
				max = *p - '0';
			}
		}
		lhs = poly_read(buf);
		for (p = buf; *p != '='; p++);
		rhs = poly_read(++p);
		for (i = 0; i < MAX; i++) {
			lhs.c[i] -= rhs.c[i];
		}
		for (j = 0; j < MAX; j++) {
			if (lhs.c[j])
				break;
		}
		if (j == MAX) {
			printf("%d+\n", max + 1);
			continue;
		}
		memcpy(&rhs, &lhs, sizeof(rhs));
		memset(&lhs, 0, sizeof(lhs));
		for (i = 0; i < MAX - j; i++) {
			lhs.c[i] = rhs.c[i + j];
		}
		find_div(lhs.c[0]);
		fail = 1;
		for (i = 0; i < ndiv; i++) {
			if (div[i] <= max)
				continue;
			if (check(div[i])) {
				if (!fail) {
					printf(" ");
				}
				fail = 0;
				printf("%d", div[i]);
			}
		}
		if (fail) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
