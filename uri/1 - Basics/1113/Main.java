import java.util.*;
class Main{
  public static void main(String [] args){
      Scanner scanner = new Scanner(System.in);
      int x, y, aux;
      
      while(true){
        x = scanner.nextInt();          
        y = scanner.nextInt();          

        if(x == y) break;
        
        if(x > y)
             System.out.println("Decrescente");
        else
            System.out.println("Crescente");
                       
      }

  }

}