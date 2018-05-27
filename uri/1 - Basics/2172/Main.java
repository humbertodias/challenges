import java.util.*;

public class Main{

    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);
        double x,m;
        while(scanner.hasNext()){
            x = scanner.nextDouble();
            m = scanner.nextDouble();
            if(x == 0 || m == 0) break;
            System.out.printf("%.0f\n", (m*x) );
        }

    }
}