#include <iostream>

using namespace std;
int main() {
unsigned long long a, r=0, aux = 0;
while ( cin >> a ){
	if (a==3) cout << "0\n" ;
	else if (a==4) cout << "2\n";
	else{   
	   r=0, aux=0;
	   for (int i=2; i<a-1; i++){
	      r=aux+i;
	      aux=r;   // se digitar 5 = 5; 6 = 9; 7 =14; 2+3+4+5+6...
	   }
	cout << aux << endl;
	}

}
return 0;
}