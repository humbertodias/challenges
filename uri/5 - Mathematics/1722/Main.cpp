#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// F_n = 1/sqrt(5) * ((1/2 + sqrt(5)/2)^n - (1/2 - sqrt(5)/2)^n) <= 2^n+1
// therefore there aren't too many (less than 2*2*log(10^100) approx. 800) fibs

typedef vector <string> tVec;

string add(string s1, string s2) {
  string r(101u, '0');
  int carry = 0;
  for (int i=100; i >= 0; i--) {
  int next = carry + (s1[i]-'0') + (s2[i]-'0');
  r[i] = (next % 10) + '0';
        carry = next / 10;
  }
  return r;
}

int main() {
  string s(101u, '0');
  tVec   v;
  s[100] = '1';
  v.push_back(s);
  s[100] = '2';
  v.push_back(s);
  while (1) {
     s = add(v[v.size()-2], v[v.size()-1]);  
     if (s > "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
       break;
     v.push_back(s);
  }

  while (1) {
    string a, b;
    cin >> a >> b;
    if (b == "0")
      break;
    while (a.length() < 101) a = "0" + a;
    while (b.length() < 101) b = "0" + b;
    int pos;
    for (pos = 0; pos < v.size() && v[pos] < a; pos++);
    int counter = 0;
    for ( ; pos < v.size() && v[pos] <= b; pos++, counter++);
    cout << counter << endl;        
  }

  return 0;
}  
