#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 99999

char str [N], asci[N], freq[N];
int len, l;
void bubsort   (char str[]);
void mulbubsort();
int main()
{
	int	i, j, f = 1, flag, count;
	while (gets(str)) {
		if (f > 1)
			printf("\n");
		len = strlen(str);
		bubsort(str);
		j = 0;
		for (i = 0; i < len; i++) {
			count = 0;
			flag = 0;
			asci[j] = str[i];
			while (asci[j] == str[i] && i < len) {
				count++;
				freq[j] = count;
				i++;
				flag = 1;
			}
			if (flag == 1)
				i -= 1;
			j++;
		}
		l = j;
		mulbubsort();
		for (i = 0; i < j; i++)
			printf("%d %d\n", asci[i], freq[i]);
		f++;
	}

	return 0;
}

void bubsort(char str[])
{
	int	t = len - 1, i, j, temp;
	for (i = 0; i < t; i++) {
		for (j = 0; j < t - i; j++) {
			if (str[j] > str[j + 1]) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

void mulbubsort()
{
	int	t = l - 1,	i, j;
	char temp1, temp2;
	for (i = 0; i < t; i++) {
		for (j = 0; j < t - i; j++) {
			if (freq[j] > freq[j + 1]) {
				temp1 = freq[j];
				temp2 = asci[j];
				freq[j] = freq[j + 1];
				asci[j] = asci[j + 1];
				freq[j + 1] = temp1;
				asci[j + 1] = temp2;
			} else if (freq[j] == freq[j + 1]) {
				if (asci[j] < asci[j + 1]) {
					temp2 = asci[j];
					asci[j] = asci[j + 1];
					asci[j + 1] = temp2;
				}
			}
		}
	}
}