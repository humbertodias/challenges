import java.util.*;
class Main{
  public static void main(String []args){
      Scanner scanner = new Scanner(System.in);
      int a;
        
      while(scanner.hasNext()){
        a = scanner.nextInt();
         if(a == 2002){
            System.out.println("Acesso Permitido");
            break;
         }else{
            System.out.println("Senha Invalida"); 
         }
      }
      
  }
}