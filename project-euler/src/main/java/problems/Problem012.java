package problems;

public class Problem012
{
    static long countDivisors(long number) {
        long divisors = 0;
        for (long i = 1; i*i <= number; i++) {
            if (number % i == 0) {
                if (i*i < number) {
                    divisors += 2; // i and number/i are (different) divisors
                } else {
                    divisors += 1; // i == number/i is a divisor
                }
            }
        }
        return divisors;
    }

    static long solve(int maxDivisors) {
        long number = 1;
        long nextNum = 2;
        while (countDivisors(number) <= maxDivisors) {
            number += nextNum;
            nextNum++;
        }
        return number;
    }

    public static void main( String ... args )
    {
        System.out.println( solve(5) );
        System.out.println( solve(500) );
    }
}
