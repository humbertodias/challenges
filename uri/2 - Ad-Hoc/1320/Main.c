#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int 
gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main(){
    int T,Q,s,e;
    
    while(1){
        scanf("%d %d",&T,&Q);
        if(T == 0) break;
        
        int g = 0,a0;
        
        scanf("%d",&a0);
        a0 <<= 1;
        int i, a;
        for(i = 1;i < T;++i){
            scanf("%d",&a);
            a <<= 1;
            // g = __gcd(g,abs(a - a0));
            g = gcd(g,abs(a - a0));
        }
        
        int first = 1;
        
        while(Q--){
            scanf("%d %d",&s,&e);
            
            if(!first) putchar(' ');
            first = 0;
            
            if(T == 1){
                if(e == s || s + e == a0) putchar('Y');
                else putchar('N');
            }else if(e == s) putchar('Y');
            else if(g == 0){
                if(e == -s) putchar('Y');
                else putchar('N');
            }else{
                int x = e - s;
                
                if((e - s) % g == 0 || (e + s - a0) % g == 0) putchar('Y');
                else putchar('N');
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}