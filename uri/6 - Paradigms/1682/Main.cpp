// Problem   Genetic Code
// Algorithm Backtracking
// Runtime   O(3^n)

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;


char s[8192], *eend=s, *target=s+5000;

bool isThue()
{
  for (int len=1 ; eend-len-len>=s ; len++)
    if (strncmp(eend-len-len, eend-len, len) == 0)
      return false;
  return true;
}

bool backtrack()
{
  if (eend == target)
    return true;
  ++eend;
  for (eend[-1]='N' ; eend[-1]<='P' ; eend[-1]++)
    if (isThue() && backtrack())
      return true;
  --eend;
  return false;
}

int main()
{
  backtrack();
  int n;
  while (cin >> n)
  {
    if (n == 0) break;
    assert(1 <= n && n <= 5000);
    // cout.form("%.*s\n", n, s);
    // cout << format("%.*s\n") % n % s;
    printf("%.*s\n", n, s);
    // cout << n <<  s << endl;
  }
  return 0;
}