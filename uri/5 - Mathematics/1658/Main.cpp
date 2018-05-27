#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdio>

using namespace std;

const int MAX_STR = 100000;
const int MAX = 100000000;

int read_line()
{
	string line;
	assert(getline(cin, line));
	stringstream buf(line);
	int res;
	buf >> res;
	return res;
}

int main() {
	int n;
	while((n = read_line()) > 0) {
		assert(n >=3 && n < MAX);
		string line;
		getline(cin, line);
		assert(line.size() <= MAX_STR);
		stringstream buf(line);

		char op;
		int times;
		int turns = 0;
		int sign = 1;
		char lastop = '?';
		while (buf >> line)
		{
			int read = sscanf(line.c_str(), "%c%d", &op, &times);
			assert(read == 2 && times > 0 && times < MAX);
			assert(op != lastop);
			lastop = op;
			switch (op)
			{
			case 'r':
				turns = (turns + sign * times) % n;
				break;
			case 'm':
				if (times % 2)
					sign = -sign;
				break;
			default:
				abort();
			}
		}

		if (turns < 0)
			turns += n;

		switch (n)
		{
		case 1:
			// operations won't change anything for such a point set
			break;
		case 2:
			if (turns)
				printf("r1");	// there is no need to mirror for n=2
			break;
		default:
			if (turns == 0)
			{
				if (sign == -1)
					printf("m1");
			}
			else if (sign == -1)
			{
				// we have to mirror either before or after the rotations
				int left_t = turns;
				int right_t = n - turns;
				if (left_t < right_t)
				{
					printf("r%d m1", left_t);
				}
				else // right_t <= left_t
				{
					printf("m1 r%d", right_t);
				}
			}
			else
			{
				// we can mirror two times, or not at all
				int left_t = turns;
				int right_t = n - turns;
				if (left_t < right_t + 2)
					printf("r%d", left_t);
				else
					printf("m1 r%d m1", right_t);
			}
		}
		puts("");
	}
	assert(n == 0);
	return 0;
}