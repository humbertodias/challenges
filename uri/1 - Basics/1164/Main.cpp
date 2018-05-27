#include <iostream>
using namespace std;

long divisor_sum( long number ) { 
   long sum = 0, i ; 
   for (i = 1 ; i < number ; i++ ) 
      if ( number % i == 0 ) 
         sum += i ; 
   return sum; 
}

int main(){

	int i, n, num;
	cin >> n;
    for(i = 0; i < n; i++){
		cin >> num;

		if(divisor_sum(num) == num) cout << num << " eh perfeito" << endl;
		else cout << num << " nao eh perfeito" << endl;

    }

   return 0;
}