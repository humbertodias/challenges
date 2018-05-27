import java.util.*;
class Main{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();
        double d = scanner.nextDouble();
        double e = scanner.nextDouble();
        double f = scanner.nextDouble();

        int num = 0;

        if(a > 0.0) num++;
        if(b > 0.0) num++;
        if(c > 0.0) num++;
        if(d > 0.0) num++;
        if(e > 0.0) num++;
        if(f > 0.0) num++;
        
        System.out.printf("%d valores positivos\n", num);
             
    }
}