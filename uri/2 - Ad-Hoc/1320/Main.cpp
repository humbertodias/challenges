#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

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
    
    while(true){
        scanf("%d %d",&T,&Q);
        if(T == 0) break;
        
        int g = 0,a0;
        
        scanf("%d",&a0);
        a0 <<= 1;
        
        for(int i = 1,a;i < T;++i){
            scanf("%d",&a);
            a <<= 1;
            g = gcd(g,fabs(a - a0));
        }
        
        bool first = true;
        
        while(Q--){
            scanf("%d %d",&s,&e);
            
            if(!first) putchar(' ');
            first = false;
            
            if(T == 1){
                if(e == s || s + e == a0) putchar('Y');
                else putchar('N');
            }else if(e == s) putchar('Y');
            else if(g == 0){
                if(e == -s) putchar('Y');
                else putchar('N');
            }else{
                if((e - s) % g == 0 || (e + s - a0) % g == 0) putchar('Y');
                else putchar('N');
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}