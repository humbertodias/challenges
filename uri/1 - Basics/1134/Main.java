import java.util.*;
class Main{
  public static void main(String []args){
      Scanner scanner = new Scanner(System.in);
      int op;
      int al = 0;
      int ga = 0;
      int di = 0;
      while(true){
        op = scanner.nextInt();
        if(op == 1) al++;
        else if(op == 2) ga++;
        else if(op == 3) di++;
        else if(op == 4) break;
        else continue;
      }
      
      System.out.printf("MUITO OBRIGADO\n");
      System.out.printf("Alcool: %d\n",al);
      System.out.printf("Gasolina: %d\n",ga);
      System.out.printf("Diesel: %d\n",di);
  }
}