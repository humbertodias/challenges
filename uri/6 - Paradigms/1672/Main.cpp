// Problem   In Danger
// Algorithm Algebra
// Runtime   O(log(n))

#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
  while (1)
  {
    double d;
    cin >> d;
    int n = (int) d;
    if (n == 0) break;
    int k = 1<<30;
    while (! (n & k)) k >>= 1;
    cout << ((n ^ k) << 1) + 1 << endl;
  }
  return 0;
}