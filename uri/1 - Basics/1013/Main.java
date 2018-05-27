import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int aux=0;
        
        if(a > b)
            aux = a;
        else
            aux = b;
        
        if(aux > c)
            aux = aux;
        else
            aux = c;
        
        System.out.format("%d eh o maior\n", aux);
    }
    
}
