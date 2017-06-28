package problems;

import java.math.BigInteger;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem017 {

    private static String[] ONES  = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};  // Requires 0 <= n <= 9
    private static String[] TEENS = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    private static String[] TENS  = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    static int solve(int limit) {
        int sum = 0;
        for (int i = 1; i <= limit; i++)
            sum += toEnglish(i).length();
        return sum;
    }


    // Requires 0 <= n <= 99999
    private static String toEnglish(int n) {
        if (n < 0 || n > 99999)
            throw new IllegalArgumentException();

        if (n < 100)
            return tens(n);
        else {
            String big = "";
            if (n >= 1000)
                big += tens(n / 1000) + "thousand";
            if (n / 100 % 10 != 0)
                big += ONES[n / 100 % 10] + "hundred";

            return big + (n % 100 != 0 ? "and" + tens(n % 100) : "");
        }
    }

    // Requires 0 <= n <= 99
    private static String tens(int n) {
        if (n < 10)
            return ONES[n];
        else if (n < 20)  // Teens
            return TEENS[n - 10];
        else
            return TENS[n / 10 - 2] + (n % 10 != 0 ? ONES[n % 10] : "");
    }

    public static void main(String ... args) {
        System.out.println(solve(10));
        System.out.println(solve(1000));
    }

}
