#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	unsigned long nl, n, m;
	unsigned long f;

	scanf("%d", &nl);
	for(int i = 0; i < nl; i++) {
		scanf("%ld %ld", &n, &m);
		f = pow(n, m);
		printf("%d\n", get_int_len(f));
	}
	return 0;
}

unsigned long get_int_len (unsigned long value){
  unsigned long l=1;
  while(value>9){ l++; value/=10; }
  return l;
}
