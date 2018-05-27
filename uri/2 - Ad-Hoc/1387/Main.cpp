#include <iostream>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  while (cin >> a >> b && a)
    cout << a + b << endl;
  return 0;
}