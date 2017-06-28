package problems;

import java.math.BigInteger;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem016 {

    static long solve(int exp){
        long sum = 0;
        String bigNumber = BigInteger.valueOf(2).pow(exp).toString(10);
        for (int i = 0; i < bigNumber.length(); i++) {
            sum += Integer.valueOf(String.valueOf(bigNumber.charAt(i)));
        }
        return sum;
    }

    public static void main(String ... args) {
        System.out.println(solve(15));
        System.out.println(solve(1000));
    }

}
