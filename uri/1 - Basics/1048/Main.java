import java.util.*;

class Main{
  public static void main(String [] args){
      Scanner scanner = new Scanner(System.in);
      double sal = scanner.nextDouble();
      
      if(sal >= 0.0 && sal <= 400.00)
         System.out.printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %c\n", sal+(0.15*sal),0.15*sal, 15,'%');
      if(sal >= 400.01 && sal <= 800.00)
         System.out.printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %c\n", sal+(0.12*sal),0.12*sal, 12,'%');
      if(sal >= 800.01 && sal <= 1200.00)
         System.out.printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %c\n", sal+(0.10*sal),0.10*sal, 10,'%');
      if(sal >= 1200.01 && sal <= 2000.00)
         System.out.printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %c\n", sal+(0.07*sal),0.07*sal, 7,'%');
      if(sal > 2000.00)
         System.out.printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %c\n", sal+(0.04*sal),0.04*sal, 4,'%');

  }
}