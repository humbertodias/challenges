#include <iomanip>
#include <iostream>
using namespace std;

int main(void){
    double n;
	cout.precision(4);
	//http://www.cplusplus.com/reference/ios/ios_base/fmtflags/
	std::cout.setf (std::ios::showpos | std::ios::uppercase);
	while(cin >> n){
		 cout << scientific << n << endl;
	}
    return 0;
}