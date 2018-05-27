#include <stdio.h>
#include <math.h>
#define SWAP(a,b) (a)=(a)^(b); (b)=(a)^(b); (a)=(a)^(c);
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define PI 3.14159265358979323846
#define D 0
int main(){
  int b,a;
  double r1,r2,V1,V2,h1,h2;
  while(1){
    scanf("%d %d",&a,&b);
    if(D)fprintf(stderr,"got: %d, %d\n",a,b);
    if(!a && !b) return 0;
    //fall 1: 
    r1=a/(2.*PI);
    r1=MIN(r1,a/2.) ;
    h1=(double)b -2*r1;
    V1=PI*r1*r1*h1;
    //Fall 2:
    r2=((double)b)/(2*PI+2);
    r2=MIN(a/2.,r2);
    h2=a;
    V2=PI*r2*r2*h2;
    printf("%.3f\n",MAX(V1,V2));
  }
  return 0;
}