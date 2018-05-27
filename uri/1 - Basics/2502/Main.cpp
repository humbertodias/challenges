#include <iostream>
#include <string>
#include <map>


using namespace std;
 
int main() {
	int n, m;
	char x;
	string a, b;
	bool flag;
	while(cin >> n >> m){
		map<char, char> mymap;
		getline(cin,a);
		getline(cin,a);
		getline(cin,b);
		//cout << "a = " << a << endl << "b = " << b << endl;
		for (int i=0; i<n; i++){
			mymap.insert(pair<char,char>(b[i], a[i]));
			mymap.insert(pair<char,char>(a[i], b[i]));
		}
		for (int i=0; i<m; i++){
			getline(cin, a);
			for (int j=0; j<a.size(); j++){
				flag=false;
				x=a[j];
				if (!(a[j]>='A' && a[j]<='Z'))
					flag=true;
				if (a[j]>='a' && a[j]<='z')
					a[j]-='a'-'A';
				if (mymap.find(a[j]) != mymap.end())
					x=mymap.find(a[j])->second;
				if (flag && x>='A' && x<='Z')
					x+='a'-'A';
				cout << x;
			}
			cout << endl;
		}
		cout << endl;
	}
}