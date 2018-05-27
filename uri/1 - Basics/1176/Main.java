import java.util.*;

class Main{

    static double f[] = new double[61];

    static double fib(int n){
        if (f[n] != -1)
            return f[n];
        f[n] = fib(n - 1) + fib(n - 2);
        return f[n];
    }

    public static void main(String []args){
        Double n, i;
        for (int j = 0; j <= 60; j++) f[j] = -1;
        f[0] = 0;
        f[1] = 1;

        Scanner scanner = new Scanner(System.in);
        i = scanner.nextDouble();
        while(i-- > 0){
            n = scanner.nextDouble();
            System.out.printf("Fib(%.0f) = %.0f\n", n, fib(n.intValue()));
        }
    }

}