import java.util.*;
class Main{

    static boolean is_prime(double n){
        if (n == 2) return true;
        if (n % 2 == 0 || n < 2) return false;
        double i;
        for (i = 3; i <= Math.sqrt(n); i += 2){
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String []args){
        double i,n;
        Scanner scanner = new Scanner(System.in);
        i = scanner.nextDouble();
        while(i-- > 0){
            n = scanner.nextDouble();
            if (is_prime(n))
                System.out.printf("%.0f eh primo\n", n);
            else
                System.out.printf("%.0f nao eh primo\n", n);
        }

    }

}