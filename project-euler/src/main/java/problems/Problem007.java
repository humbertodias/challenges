package problems;

public class Problem007
{
    static boolean isPrime(int num) {
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num < 2) return false;
        int lim = (int) Math.pow(num, 0.5) + 1;
        for (int i = 3; i < lim; i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    static int solve(int limit){
        int count = 0, n = 1;
        while(count < limit){
            if(isPrime(++n))
                count++;
        }
        return n;
    }

    public static void main( String ... args )
    {
        System.out.println( solve(10_001) );
    }
}
