#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateEI (int, int, int, int, vector <vector <int> >);

int main()
{
	int C, R, N, S, X, Y, D;
	vector <int> ans;

	do {
		cin >> C >> R >> N >> S;
		if (C== 0 && R == 0 && N == 0 && S == 0) break;
		vector <vector <int> > roads (C, vector <int> (C,-1));

		for (int i = 0; i < R; ++i) {
			cin >> X >> Y >> D;
			roads[X-1][Y-1] = roads[Y-1][X-1] = D;
		}
		ans.push_back(calculateEI(C,R,N,S,roads));

	}while (C != 0 && R != 0 && N != 0 && S != 0);

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;

	return 0;
}

int calculateEI (int C, int R, int N, int S, vector <vector <int> > roads)
{
	--S;
	vector <int> ICI(C,0);
	int IEI = 0;
	int EI = 0;
	for (int i = 1; i <= N; ++i) {
		int maxICIindex = 0;
		int maxICI = -1;
		for (int j = 0; j < roads[S].size(); ++j) {
			if (S != j && roads[S][j] != -1 && ICI[j] > maxICI) {
				maxICI = ICI[j];
				maxICIindex = j;
			}
		}
		int count = 1;
		while (i <= N && count <= roads[S][maxICIindex]) {
			IEI = 0;
			for (int j = 0; j < ICI.size(); ++j) {
				++ICI[j];
				IEI += ICI[j];
			}
			
			if (count == roads[S][maxICIindex]) {
				S = maxICIindex;
				IEI -= ICI[maxICIindex];
				ICI[maxICIindex] = 0;
			} else 
				++i;
			EI += IEI;

			++count;
		}
		if (count == roads[S][maxICIindex]) --i;
	}
	return EI;
}