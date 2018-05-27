#include <stdio.h>

int main(){
    int a,b,c,d,e;
    int par = 0;
    
    scanf("%d", &a);
    if(a%2 == 0){
         par++;
    }
    scanf("%d", &b);
    if(b%2 == 0){
         par++;
    }
    scanf("%d", &c);
    if(c%2 == 0){
         par++;
    }
    scanf("%d", &d);
    if(d%2 == 0){
         par++;
    }
    scanf("%d", &e);
    if(e%2 == 0){
         par++;
    }
    
    printf("%d valores pares\n", par);
    return 0;
}