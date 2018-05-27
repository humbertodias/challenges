import java.util.*;
import java.io.*;

public class Main{


    public static long getGCD(long n1, long n2) {
        if (n2 == 0) {
            return n1;
        }
        return getGCD(n2, n1 % n2);
    }


    public static void main(String [] args)
    {
        long n, i, mod_sum, denominator, loop_prune, remainder, divi;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext())
        {
            n = scanner.nextLong();
            denominator = n * n;
            remainder = getGCD(n,denominator);
            divi = getGCD(remainder, denominator);
            System.out.printf("%d/%d\n", remainder, denominator  );
        }

    }

}

