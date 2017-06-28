package problems;

import java.math.BigInteger;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem020 {

    public static long solve (int n)  {
        return sum(fatorial(n));
    }

    static long sum(BigInteger number){
        long sum = 0;
        String bigNumber = number.toString(10);
        for (int i = 0; i < bigNumber.length(); i++) {
            sum += Integer.valueOf(String.valueOf(bigNumber.charAt(i)));
        }
        return sum;
    }


    static BigInteger fatorial(int a) {
        return a == 1 ? BigInteger.ONE : BigInteger.valueOf(a).multiply(fatorial(a - 1));
    }

    public static void main(String ... args) {
        System.out.println(solve(10));
        System.out.println(solve(100));
    }

}
