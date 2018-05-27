// Problem   Phylogenetic Trees Inherited
// Algorithm Dynamic Programming
// Runtime   O(n * l)

#include <fstream>
#include <iostream>

using namespace std;

static char seq[1024][1024];

int main ()
{
  int heap[2048], n, l;
  while (cin >> n >> l)
  {
    if (n == 0 || l == 0) break;
    for (int k=0 ; k<n ; k++)
      cin >> seq[k];
    int cost = 0;
    for (int i=0 ; i<l ; i++)
    {
      for (int k=0 ; k<n ; k++)
        heap[n+k] = 1 << (seq[k][i] - 'A');
      for (int k=n-1 ; k>0 ; k--)
        if (! (heap[k] = heap[k+k] & heap[k+k+1]))
          ++cost, heap[k] = heap[k+k] | heap[k+k+1];
      char ch = 'A';
      while (heap[1]>>=1) ++ch;
      cout << ch;
    }
    cout << ' ' << cost << endl;
  }
  return 0;
}
