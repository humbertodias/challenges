//Problema A: Maior Número de Um Algarismo.
#include <cstdio>

using namespace std;

char s[500],s2[500];

int maior(char *c){
	int a = 0;
	for(int i=0;c[i];i++) a += c[i]-48;
	if(a > 9){
		sprintf(c,"%d",a);
		return maior(c);
	}
	return a;
}

int main(){
	int n,m;
	while(scanf("%s%s",&s,&s2)){
		getchar();
		n = maior(s);
		m = maior(s2);
		if (n == 0 && m == 0) break;
		if(n == m) printf("0\n");
		else printf("%d\n",(n > m)?1:2);
	}
	return 0;
}