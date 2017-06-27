package problems;

import java.util.stream.IntStream;

public class Problem001
{
    static boolean isMultipleOf3Or5(int num){
        return num % 3 == 0 || num % 5 == 0;
    }

    static int solve(int limit){
        return IntStream.range(3,limit)
                .filter(Problem001::isMultipleOf3Or5)
                .sum();
    }

    public static void main( String ... args )
    {
        System.out.println( solve(1000) );
    }
}
