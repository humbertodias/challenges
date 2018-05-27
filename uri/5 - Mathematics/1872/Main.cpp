#include <cstring>
#include <cstdio>
#include <cstdlib> // atoi
#include <algorithm> //reverse

using namespace std;
 
char s[100],s2[100],s3[100];
 
int ispalindrome(char *c){
	char s[500];
	strcpy(s,c);
	reverse(s,s+strlen(s));
	return (strcmp(s,c) == 0);
}
 
void removetrailing(char *c){
	int a=-1,i = 0;
	for(i=0;s[i];i++){
		if(c[i] != '.' ) continue;
		a = i;
		break;
	}
	for(;s[i];i++){
		if(c[i] != '0' && c[i] != '.') a = -1;
		else if(a == -1) a = i;
	}
	if(a != -1) s[a] = 0;
}
 
int main(){
	double n,m;
	int t,a;
	scanf("%d",&t);
	while(t--){
		getchar();
		scanf("%s",&s);
		if(ispalindrome(s)) printf("0\n");
		else{
			a = atof(s);
			n = atof(s);
			sprintf(s,"%d",a);
			strcpy(s2,s);
			a = strlen(s);
			reverse(s2,s2+a);
			sprintf(s3,"%s.%s",s,s2);
			m = atof(s3);
			if(n < m){
				n = m-n;
				sprintf(s,"%lf",n);
				removetrailing(s);
				printf("%s\n",s);
			}
			else{
				m = n+1;
				a = m;
				sprintf(s2,"%d",a);
				if(ispalindrome(s2)){
					n = a-n;
					sprintf(s,"%lf",n);
					removetrailing(s);
					printf("%s\n",s);
				}
				else{
					sprintf(s,"%d",(int)m);
					strcpy(s2,s);
					a = strlen(s);
					reverse(s2,s2+a);
					sprintf(s3,"%s.%s",s,s2);
					n = atof(s3)-n;
					sprintf(s,"%lf",n);
					removetrailing(s);
					printf("%s\n",s);
				}
			}
		}
	} 
 	return 0;
}