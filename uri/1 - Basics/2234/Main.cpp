#include <iostream>
#include <iomanip>

using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double a, b;
  cin >> a >> b;

  cout << fixed << setprecision(2) << a / b << endl;
  return 0;
}
