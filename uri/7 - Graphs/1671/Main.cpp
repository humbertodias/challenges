// Problem   Code
// Algorithm Euler Tour (Depth First Search)
// Runtime   O(10^(n+1))

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

bool edge[100000][10];
int nstates;
string out;

void dfs(int q)
{
  // We are in state q and press the key i.
  for (int i=0 ; i<10 ; i++)
    if (edge[q][i])
    {
      edge[q][i] = false;
      dfs((q * 10 + i) % nstates);
      out += (char) ('0' + i);
    }
}

int main()
{
  while (1)
  {
    int n;
    cin >> n;
    if (n == 0) break;
    assert(1 <= n && n <= 6);
    // There are 10^(n-1) states.
    nstates = 1;
    for (int k=1 ; k<n ; k++)
      nstates *= 10;
    // From every state, by pressing a key, one of 10 states is reachable.
    for (int q=0 ; q<nstates ; q++)
      fill_n(edge[q], 10, true);
    // We always start with pressing the 0 key n-1 times.
    cout << string(n-1, '0');
    // Produce an Euler tour in reverse order and output it.
    out = "";
    dfs(0);
    reverse_copy(out.begin(), out.end(), ostream_iterator<char>(cout, ""));
    cout << endl;
  }
  return 0;
}