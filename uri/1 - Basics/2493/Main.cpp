#include <iostream>
#include <string>

using namespace std;
 
int main() {
 
	int t;
	string exp[50][2];
	string resp[50][3];
 
	while(cin >> t){
		for(int i=0; i<t; i++){
			cin >> exp[i][0];
			cin >> exp[i][1];
			cout << exp[i][0] << " " << exp[i][1] << endl;
		}
		for(int i=0; i<t; i++){
			cin >> resp[i][0];
			cin >> resp[i][1];
			cin >> resp[i][2];
			cout << resp[i][0] << " " << resp[i][1] << " " << resp[i][2] << endl;
		}
	}
	return 0;
}