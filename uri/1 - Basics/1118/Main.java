import java.util.*;
class Main{
  public static void main(String []args){
      Scanner scanner = new Scanner(System.in);
      float x=0, y=0, z=0, n = 0;
      while(true){
          x = scanner.nextFloat();
          if(n == 1){
               
            if(x == 2){
               break;
            }else if(x == 1){
               n = 0;
               continue;
            }
            else{
               System.out.printf("novo calculo (1-sim 2-nao)\n");
               continue;
            }

          }else{
              if(x < 0 || x > 10){
                System.out.printf("nota invalida\n");
              }
              else if(z == 0){
                y = x;
                z = 1;
              }
              else{
                 System.out.printf("media = %.2f\n", (x+y)/2.00);
                 z = 0;
                 n = 1;
              }
          }
          
          if(n == 1) System.out.printf("novo calculo (1-sim 2-nao)\n");
                       
      }    
  }
}