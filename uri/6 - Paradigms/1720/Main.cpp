// Problem   Mondriaan's Dream
// Algorithm Dynamic Programming, Backtracking
// Runtime   O(r * (sqrt(2)+1)^c)

#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int,int> ipair;
typedef vector<ipair> ipvec;

static double cnt[12][1<<11];
ipvec trans;
int rows, cols;

void backtrack (int n, int from, int to)
{
  if (n > cols) return;
  if (n == cols)
  {
    trans.push_back (ipair (from, to));
    return;
  }
  backtrack (n+2, from<<2, to<<2);
  backtrack (n+1, from<<1, (to<<1)|1);
  backtrack (n+1, (from<<1)|1, to<<1);
}

int main ()
{
  cout.setf (ios::fixed);
  cout.precision (0);
  while (cin >> rows >> cols)
  {
    if (rows == 0 || cols == 0) break;
    if (rows < cols) { int t = rows; rows = cols ; cols = t; }

    // calculate map of possible transitions by linear backtracking
    trans.clear ();
    backtrack (0, 0, 0);

    for (int r=0 ; r<=rows ; r++)
      fill_n (cnt[r], 1<<cols, 0);
    
    cnt[0][0] = 1;
    for (int r=0 ; r<rows ; r++) // the r topmost rows are already filled
      for (ipvec::iterator it = trans.begin() ; it != trans.end() ; ++it)
        cnt[r+1][(*it).second] += cnt[r][(*it).first];

    cout << cnt[rows][0] << endl;
  }
  return 0;
}
