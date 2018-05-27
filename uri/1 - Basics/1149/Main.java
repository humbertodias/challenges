import java.util.*;
class Main{
  public static void main(String []args){
      Scanner scanner = new Scanner(System.in);      
      int a, n, i;
      int soma = 0;
      
      while(scanner.hasNextInt()){
        a = scanner.nextInt();
        n = scanner.nextInt();
        while(n <= 0){ 
          n = scanner.nextInt();
        }
        for(i = 0; i < n; i++){
             soma += (a + i);
        }
        System.out.println(soma);
        soma = 0;
      }

  }
}