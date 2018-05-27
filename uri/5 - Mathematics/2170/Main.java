import java.util.*;

public class Main{

    static double percentual(double x, double y){
      return (y / x - 1)  * 100;
    } 

    public static void main(String args[]){
        Scanner scanner  = new Scanner(System.in);
        double a,b;
        int i=1;

        while(scanner.hasNext()){
          a = scanner.nextDouble();
          b = scanner.nextDouble();
          System.out.format("Projeto %d:\n", i++);
          System.out.format("Percentual dos juros da aplicacao: %.2f %%\n\n", percentual(a,b) );
        }
    }
}