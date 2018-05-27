#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>
#include <vector>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  long long n;
  while (cin >> n && n) {
    for (long long i = 1; i * i <= n; ++i) {
      if (i > 1) cout << " ";
      cout << i * i;
    }
    cout << endl;
  }
  return 0;
}

