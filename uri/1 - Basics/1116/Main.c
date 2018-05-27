#include <stdio.h>

int main(){
    
    int x, y, z, i;
    scanf("%d", &x);
    
    for(i = 0; i < x; i++){
        scanf("%d %d", &y, &z);
          
        if(z == 0){
           printf("divisao impossivel\n");
        } else{
           printf("%.1f\n", (float)y/(float)z);
        }
    }
    
    return 0;
}