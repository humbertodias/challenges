import java.util.*;
class Main{
  public static void main(String []args){
      int a,b, aux, i;
      Scanner scanner = new Scanner(System.in);
      a = scanner.nextInt();
      b = scanner.nextInt();
      
      if(b < a){
        aux = a;
        a = b;
        b = aux;
      }
      
      for(i = a+1; i < b; i++){
          if(i%5 == 2 || i%5 == 3){
             System.out.println(i);
          }
      }

  }
}