#include <stdio.h>

long divisor_sum( long number ) { 
   long sum = 0, i ; 
   for (i = 1 ; i < number ; i++ ) 
      if ( number % i == 0 ) 
         sum += i ; 
   return sum; 
}

int main(){

	int i, n, num;
	scanf("%d", &n);
    for(i = 0; i < n; i++){
		scanf("%d", &num);

		if(divisor_sum(num) == num) printf("%d eh perfeito\n", num);
		else printf("%d nao eh perfeito\n", num);

    }
    return 0;
}