#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace	std;

struct block {
	int		mode, i, s, e, a;
};

struct word {
	char	arr [205];
	int		s, e, l, id;
};

///pre_process
void		pre_process();
void		cpy       (int i, int j, char tmp[]);
bool		compare   (word & x, word & y);
bool		comp      (word x, word y);

///Algo func
int		tabular    ();
pair < int     , int >check2(int curr, int end);
void		trace     (int start, int end);
void		trace2    (int curr, int end, int cnt);

///aarrayS
char	aarray    [205];
pair < int, int >dp3[20200][205];
block	dp2      [205][205];
word	pro       [20200];
int		tr         [20200][205];
int		visited    [20200][205];
int		ind        [205][205];
int		dp         [205][205];

///VARIABLES
const int	inf = 9999999;
int	cases = 0,	m, l, taken, flag;

int main()
{
	memset(visited, -1, sizeof(visited));
	while (scanf("%s", aarray) != EOF) {
		l = strlen(aarray);
		pre_process();
		printf("%d ", tabular());
		trace(0, l);
		printf("\n");
		cases++;
	}

	return 0;
}

int tabular()
{
	int	end;
	for (int start = l; start >= 0; start--)
		for (int len = 0; len <= l; len++) {
			end = start + len;
			if (end > l)
				break;

			int &ret = dp[start][end];
			ret = inf;
			//end - start;
			block & x = dp2[start][end];
			int		tmp;

			if (start == l || end <= start)
				ret = 0;
			else {
				///skip char
						tmp = dp[start + 1][end] + 1;
				if (tmp <= ret)
					x.mode = 0, ret = tmp;

				///split int two parts
				for             (int i = start + 1; i < end; i++) {
					tmp = dp[start][i] + dp[i][end];
					if (tmp <= ret)
						x.mode = 1, x.i = i, ret = tmp;
				}

				///the working algorithm
					for (int i = start + 1; i < end; i++) {
					int		ll = i - start;
					int		h = ind[end - ll][end];
					int		h2 = ind[start][i];
					pair < int     , int >f;
					if (pro[h].id != pro[h2].id || (end - start) / ll < 2)
						tmp = inf;
					else
						f = check2(h2, end - ll), tmp = 3 + dp[start][i] + f.first;

					if (tmp <= ret) {
						ret = tmp;

						x.mode = 2, x.i = i, x.s = taken, x.e = flag;
						x.a = f.second + 1;
					}
				}
			}
		}

	return dp[0][l];
}

pair <int, int> check2(int curr, int end)
{
	pair < int     , int >&ret = dp3[curr][end];
	int            &flag = visited[curr][end];
	if (flag == cases)
		return ret;
	flag = cases;
	ret.first = inf;
	ret.second = 0;

	if (pro[curr].l + pro[curr].s == end) {
		ret.second = 1;
		ret.first = 0;
		return ret;
	}
	if (pro[curr].l + pro[curr].s > end) {
		ret.first = dp[pro[curr].s][end] + 3;
		return ret;
	}
	if (pro[curr + 1].id != pro[curr].id || pro[curr + 1].s >= end) {
		ret.second++;
		ret.first = dp[pro[curr].e][end] + 3;
		return ret;
	}
	///take it && decide to take the others
		for (int i = curr + 1; i < m && pro[i].id == pro[curr].id && pro[i].s <= end; i++)
		if (pro[i].s >= pro[curr].e) {
			pair < int     , int >tmp = check2(i, end);
			if (pro[curr].e != pro[i].s)
				tmp.first += 3 + dp[pro[curr].e][pro[i].s];

			if (tmp.first <= ret.first) {
				tr[curr][end] = i;
				ret = tmp;
				ret.second += 1;
			}
		}
	return ret;
}

void trace2(int curr, int end, int cnt)
{
	pair < int     , int >ret = dp3[curr][end];

	if (pro[curr].l + pro[curr].s == end)
		return;

	if (pro[curr].l + pro[curr].s > end) {

		printf("{");
		trace(pro[curr].s, end);
		printf("}");
		printf("%d", cnt + 1);
		return;
	}
	if (pro[curr + 1].id != pro[curr].id || pro[curr + 1].s >= end) {
		printf("{");
		trace(pro[curr].e, end);
		printf("}");
		printf("%d", cnt + 1);
		return;

	}
	///take it && decide to take the others
	int	i = tr[curr][end];

	if (pro[curr].e != pro[i].s) {
		printf("{");
		trace(pro[curr].e, pro[i].s);
		printf("}");
		printf("%d", cnt + 1);
		trace2(i, end, cnt + 1);
	} else
		trace2(i, end, cnt + 1);

	return;
}

void trace(int start, int end)
{
	if (start == l || end <= start)
		return;

	block		x = dp2[start][end];

	if (x.mode == 0) {
		printf("%c", aarray[start]);
		trace(start + 1, end);
		return;
	}
	if (x.mode == 1) {
		trace(start, x.i);
		trace(x.i, end);
		return;
	}
	if (x.mode == 2) {
		printf("[");
		trace(start, x.i);
		printf("]");
		printf("%d", x.a);
		int		h2 = ind[start][x.i];
		trace2(h2, end - pro[h2].l, 0);
		return;
	}
}

void pre_process()
{
	int	k = 0;
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j <= l; j++) {
			cpy(i, j, pro[k].arr);
			pro[k].s = i;
			pro[k].e = j;
			pro[k].l = j - i;
			k++;
		}
	m = k;
	sort(pro, pro + m, comp);
	int		curr_id = 0;
	int		prev_i = 0;

	for (int i = 0; i < k; i++) {
		if (compare(pro[i], pro[prev_i]))
			pro[i].id = curr_id;
		else {
			curr_id++;
			pro[i].id = curr_id;
			prev_i = i;
		}
		ind[pro[i].s][pro[i].e] = i;
	}
	return;
}

bool compare(word & x, word & y)
{
	if (x.l != y.l)
		return false;
	else
		return (strcmp(x.arr, y.arr) == 0);
}

void cpy(int i, int j, char tmp[])
{
	int	k = 0;
	for (int f = i; f < j; f++)
		tmp[k] = aarray[f], k++;
	tmp[k] = '\0';
	return;
}

bool comp(word x, word y)
{
	int	t = strcmp(x.arr, y.arr);

	if (t != 0)
		return (t < 0);

	if (x.s != y.s)
		return (x.s < y.s);

	return (x.e < y.e);
}
