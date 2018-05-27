#include <sstream>
#include <iostream>
#include <algorithm> // transform
using namespace std;

string hex(long n){
     std::stringstream sstream;
     sstream << std::hex << n;
     string ss = sstream.str();
     transform(ss.begin(), ss.end(), ss.begin(), (int (*)(int))std::toupper);
     return ss;
}

int main(void){
     long n;
     while(cin >> n)
     cout << hex(n) << endl;
     return 0;
}