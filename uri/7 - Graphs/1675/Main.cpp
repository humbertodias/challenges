// Problem   Binary Search Heap Construction
// Algorithm Order-Statistic Trees
// Runtime   O(n*log(n))

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> // sort

using namespace std;

const int n2 = 1<<16; // must be a power of 2
string l[n2];         // the labels
int p[n2];            // the priorities
int ost[2*n2];        // an order-statistic tree containing indexes to labels and priorities

// for sorting by comparing labels
bool lcmp(const int ia, const int ib)
{
  return l[ia] < l[ib];
}

void recurse(int from, int to)
{
  assert(n2 <= from && from <= to && to < 2*n2);
  // r will become the index in [from..to] with maximal priority
  int r = p[ost[from]] > p[ost[to]] ? from : to;
  // move upwards in the tree until the common predecessor is reached
  for (int f=from, t=to ; f<t ; f/=2, t/=2 )
  {
    // the internal nodes between f and t store the maximal priorities
    // of the nodes in subintervals of (from..to)
    if ((f%2 == 0) && (f+1 < t) && p[ost[f+1]] > p[ost[r]]) r = f+1;
    if ((t%2 == 1) && (t-1 > f) && p[ost[t-1]] > p[ost[r]]) r = t-1;
  }
  // p[ost[r]] is already maximal in p[ost[from]]..p[ost[to]], move downwards
  // to find the node in the bottom level from which this priority originates
  while (r < n2)
  {
    if (ost[r] == ost[r*2])
      r = r*2;
    else if (ost[r] == ost[r*2+1])
      r = r*2+1;
    else
      assert(false);
  }
  assert(from <= r && r <= to);
  // split [from..to] at r into a left sub-treap and a right sub-treap
  cout << '(';
  if (from < r) recurse(from, r-1);
  cout << l[ost[r]] << '/' << p[ost[r]];
  if (r < to) recurse(r+1, to);
  cout << ')';
}

int main()
{
  int n;
  while (cin >> n)
  {
    if (n == 0) break;
    assert(1 <= n && n <= 50000);
    // parse the labels and priorities
    for (int i=0 ; i<n ; i++)
    {
      string s;
      cin >> s;
      int separator = s.find('/');
      assert(0 <= separator && separator < (int)s.size());
      l[i] = s.substr(0, separator);
      assert(sscanf(s.substr(separator+1).c_str(), "%d", &p[i]) == 1);
    }
    // the bottom level of the order-statistic tree consists of the labels in sorted order
    for (int i=0 ; i<n ; i++)
      ost[n2+i] = i;
    sort(ost+n2, ost+n2+n, lcmp);
    // build the higher levels of the tree
    for (int a=n2, b=n2+n-1 ; a>1 ; a/=2, b/=2)
    {
      for (int i=a ; i<b ; i+=2)
        ost[i/2] = p[ost[i]] > p[ost[i+1]] ? ost[i] : ost[i+1];
      if (b%2 == 0) // the rightmost node is the single child of its parent
        ost[b/2] = ost[b];
    }
    // recursively output the treap
    recurse(n2, n2+n-1);
    cout << endl;
  }
  return 0;
}
