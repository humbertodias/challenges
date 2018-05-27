import java.util.*;

class Main{

    static double low(long n) {
        return n/Math.log(n);
    }

    static double high(long n) {
        return 1.25506 * low(n);
    }

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.printf("%.1f %.1f\n", low(N), high(N) );
    }
}