package problems;

import java.util.stream.IntStream;
import java.util.stream.LongStream;

public class Problem010
{

    static boolean isPrime(long num) {
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num < 2) return false;
        int lim = (int) Math.pow(num, 0.5) + 1;
        for (int i = 3; i < lim; i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    static long solve(int limit){
        return LongStream.range(2,limit)
                .parallel()
                .filter(Problem010::isPrime)
                .sum();
    }

    public static void main( String ... args )
    {
        System.out.println( solve(10) );
    }
}
