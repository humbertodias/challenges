package problems;

import java.math.BigInteger;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem025 {

    public static long solve (int digits) {
        BigInteger currentFibNum = BigInteger.ONE;
        BigInteger prevFibNum    = BigInteger.ONE;
        long index = 2;
        while(currentFibNum.toString().length() < digits){
            BigInteger temp = prevFibNum.add(currentFibNum);
            prevFibNum = currentFibNum;
            currentFibNum = temp;
            index++;
        }
        return index;
    }

    public static void main(String ... args) {
        System.out.println(solve(3));
        System.out.println(solve(1000));
    }

}
