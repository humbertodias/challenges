#include <stdio.h>

int mdc(int a,int b)
{
    if(b == 0) return a;
    return mdc(b,a%b);
} 

int main(){
    int n, a, b, c, d, i;
    char op;
    int max, min, res;
    
    scanf("%d\n",&n);
    for(i = 0; i < n; i++){
            scanf("%d / %d %c %d / %d",&a,&b,&op,&c,&d);
            if(op == '/'){
                  max = b*c;
                  res = a*d;
                  printf("%d/%d = ",res,max);
                  min = mdc(res,max);
                  printf("%d/%d\n",res/min,max/min);
            }
            else{
                 max = b*d;
                 if(op == '+') res = a*(max/b) + c*(max/d);
                 else if(op == '-') res = a*(max/b) - c*(max/d);
                 else if(op == '*') res = a*c;
                 printf("%d/%d = ",res,max);
                 min = mdc(res,max);
                 if(min < 0) min = -1*min;
                 printf("%d/%d\n",res/min,max/min);
            }
    }
    return 0;
}