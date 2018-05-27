import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner scanner  = new Scanner(System.in);
        int T, C, E;
        String [] termos;
        while(scanner.hasNext()){
          T = Integer.parseInt(scanner.nextLine());
          termos = scanner.nextLine().trim().split("\\+");
          for(String termo : termos){
            if(termo.length() < 1) break;
            C = Integer.parseInt(termo.trim().split("x")[0]);
            E = Integer.parseInt(termo.trim().split("x")[1]);
            if(T>1)
              System.out.format("%dx%d + ", C*E, T--);
            else{
              System.out.format("%dx\n", C*E);
            }
          }
        }
    }
}