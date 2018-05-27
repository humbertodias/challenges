#include <iostream>
using namespace	std;

int	flag, n, m;

void 
lompat(int i, int pos)
{
	if ((n >= 49) || (m == 1) || (m == 4) || (m == 9) || (m == 16) || (m == 25) || (m == 36)) {
		flag = 1;
		return;
	} else {
		if ((pos > n) || (pos < 0))
			return;
		if (pos == m) {
			flag = 1;
			return;
		}
		if (flag != 1) {
			lompat((i + 1), (pos + (2 * i - 1)));
			lompat((i + 1), (pos - (2 * i - 1)));
		}
	}


}

int main()
{
	cin >> n >> m;
	while (n | m) {
		flag = 0;
		lompat(2, 1);
		if (flag == 1)
			cout << "Let me try!" << endl;
		else
			cout << "Don't make fun of me!" << endl;
		cin >> n >> m;
	}
	return 0;
}
