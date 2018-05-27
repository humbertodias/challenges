#include <iostream>
#include <algorithm>
#include <string>

using namespace	std;

int main()
{
	int	N, count = 0, t;

	cin >> N;
	while (N != 0) {
		int	c [10] = {0};
		string s;
		for (int i = 0; i <= N; i++) {
			getline(cin, s);
			if (s == "um quadrado")
				c[0]++;
			else if (s == "um triangulo")
				c[2]++;
			else if (s == "um circulo")
				c[1]++;
			else if (s == "dois quadrados")
				c[3]++;
			else if (s == "dois circulos")
				c[4]++;
			else if (s == "dois triangulos")
				c[5]++;
			else if (s == "tres quadrados")
				c[6]++;
			else if (s == "tres circulos")
				c[7]++;
			else if (s == "tres triangulos")
				c[8]++;
		}
		for (int k = 0; (k < 9) && (N - 3 * count > 2); k++) {
			if (c[k] >= 3) {
				count += c[k] / 3;
				c[k] %= 3;
			}
		}

		if (((N - 3 * count) > 2) && (c[0] * c[4] * c[8]) != 0) {
			t = min(c[0], min(c[4], c[8]));
			c[0] -= t;
			c[4] -= t;
			c[8] -= t;
			count += t;
		}
		if (((N - 3 * count) > 2) && (c[0] * c[5] * c[7]) != 0) {
			t = min(c[0], min(c[5], c[7]));
			c[0] -= t;
			c[5] -= t;
			c[7] -= t;
			count += t;
		}
		if (((N - 3 * count) > 2) && (c[1] * c[3] * c[8]) != 0) {
			t = min(c[1], min(c[3], c[8]));
			c[1] -= t;
			c[3] -= t;
			c[8] -= t;
			count += t;
		}
		if (((N - 3 * count) > 2) && (c[1] * c[5] * c[6]) != 0) {
			t = min(c[1], min(c[5], c[6]));
			c[1] -= t;
			c[5] -= t;
			c[6] -= t;
			count += t;
		}
		if (((N - 3 * count) > 2) && (c[2] * c[4] * c[6]) != 0) {
			t = min(c[2], min(c[4], c[6]));
			c[2] -= t;
			c[4] -= t;
			c[6] -= t;
			count += t;
		}
		if (((N - 3 * count) > 2) && (c[2] * c[3] * c[7]) != 0) {
			t = min(c[2], min(c[3], c[7]));
			c[2] -= t;
			c[3] -= t;
			c[7] -= t;
			count += t;
		}
		for (int j = 0; (j < 3) && ((N - 3 * count) > 2); j++) {
			t = min(c[j], min(c[j + 3], c[j + 6]));
			c[j] -= t;
			c[j + 3] -= t;
			c[j + 6] -= t;
			count += t;
		}

		cout << count << '\n';
		count = 0;
		cin >> N;
	}
	return 0;
}
