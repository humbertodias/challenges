#include <stdio.h>

int main(){
    
    float x, y=0, z=0;
    while(1){
        scanf("%f",&x);
        if(x < 0 || x > 10){
          printf("nota invalida\n");
        }
        else if(z == 0){
          y = x;
          z = 1;
        }else{
          printf("media = %.2f\n", (y+x)/2);
          break;
        }
    } 
    return 0;
}