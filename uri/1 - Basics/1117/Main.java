import java.util.*;
class Main{
  public static void main(String [] args){
      Scanner scanner = new Scanner(System.in);
      float x, y=0, z=0;
      while(true){
        x = scanner.nextFloat();
          if(x < 0 || x > 10){
            System.out.printf("nota invalida\n");
          }
          else if(z == 0){
            y = x;
            z = 1;
          }else{
            System.out.printf("media = %.2f\n", (y+x)/2);
            break;
          }
      } 

  }
}