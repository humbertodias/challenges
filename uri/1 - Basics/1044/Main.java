import java.util.*;

class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int aux;
        if(a < b){
         aux = a;
         a = b;
         b = aux;
        }
        
        if(a%b == 0)
           System.out.printf("Sao Multiplos\n");
        else
           System.out.printf("Nao sao Multiplos\n");
               
    }
}