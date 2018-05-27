#include <stdio.h>

int long carry_num (int long a,int long b);
int main()
{
      int long a,b,sum=0,op=0,d1,d2,carry;
      while(scanf("%ld %ld",&a,&b)==2){
            if(a==0 && b==0)
            break;

            op=carry_num(a,b);
            if(op==0)
            printf ("No carry operation.\n");
            else if(op==1)
            printf ("1 carry operation.\n");
            else
           printf("%ld carry operations.\n",op);
      }
      return 0;
}

int long carry_num(int long a,int long b)
{
      int long op,carry,d1,d2,sum;
            op=0;
            carry=0;
            while(1){
                       d1=a%10;
                       d2=b%10;
                        sum=d1+d2+carry;
                        if(sum>=10){
                              op++;
                             carry=1;
                        }
                        else {
                              carry=0;
                        }
                       a=a/10;
                       b=b/10;
                       if(a==0 && b==0)
                       break;
            }
            return op;
}