// Problem   Fold
// Algorithm Dynamic Programming
// Runtime   O(n^3)

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool av(char c1, char c2)
{
  return (c1=='A' && c2=='V') || (c1=='V' && c2=='A');
}

int main()
{
  string s;
  while (cin >> s)
  {
    int n = s.size();
    vi match(n, 0);
    // match[i] is the maximal d such that s[i-d..i-1] and s[i+1..i+d]
    // are reverse complementary, i.e., the 2*(d+1) stripes i-d..i
    // and i+1..i+d+1 can be folded upon each other.
    for (int k=0 ; k<n ; k++)
      for (int i=k-1,j=k+1 ; 0<=i && j<n && av(s[i], s[j]) ; i--,j++)
        ++match[k];
    ++n;
    vvi dp(n, vi(n, 0));
    // dp[i][j], where i<=j, is the minimum number of folding steps
    // required to produce the turns between stripes i and j,
    // inclusively, i.e., those described in s[i..j-1].
    for (int d=1 ; d<n ; d++)
      for (int i=0,j=i+d ; j<n ; i++,j++)
      {
        dp[i][j] = n;
        for (int k=i,l=k+1 ; k<j ; k++,l++)
          if (match[k] >= min(k-i, j-l))
            dp[i][j] = min(dp[i][j], 1+max(dp[i][k], dp[l][j]));
        assert(dp[i][j] < n);
      }
    cout << dp[0][n-1] << endl;
  }
  return 0;
}