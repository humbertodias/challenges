package problems;

public class Problem003 {

    // http://www.jameselsey.co.uk/blogs/techblog/project-euler-problem-3-largest-prime-factor/
    public static int solve(long number) {
        int i;

        // start dividing by 2, as that is the smallest prime number, keep going until we're trying to divide the number by itself,
        // this indicates we've finished.
        for (i = 2; i <= number; i++) {
            //We're only interested in "i" if it divides evenly by the number
            if (number % i == 0) {
                // divide number by i and re-assign, so we can start counting up from 2 again
                number /= i;
                // the for loop will increment i, however if number is divisible by i with no remainder, we want to try again.
                // for example, if we divide number 2000 by 2, we want to decrement i so we can try to divide the resulting 1000 by 2 again
                i--;
            }
        }

        return i;
    }

    public static void main( String ... args )
    {
        System.out.println(solve(600851475143L));
    }

}
