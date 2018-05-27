import java.util.*;
import java.io.*;

public class Main{

    static long euclides(long a, long b)
    {
        long r;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }


    static long euclides_rec(long a, long b)
    {
        if (b == 0)
          return a;
        else
          return euclides_rec(b, a % b);
    }


    static long gcd(long a, long b){
        if( a<0 ) a = -a;
        if( b<0 ) b = -b;
        while( b!=0 ){
            a %= b;
            if( a==0 ) return b;
            b %= a;
        }
        return a;
    }    

 static long gcd_bin(long p, long q) {
    if (q == 0) return p;
    if (p == 0) return q;

    // p and q even
    if ((p & 1) == 0 && (q & 1) == 0) return gcd(p >> 1, q >> 1) << 1;

    // p is even, q is odd
    else if ((p & 1) == 0) return gcd(p >> 1, q);

    // p is odd, q is even
    else if ((q & 1) == 0) return gcd(p, q >> 1);

    // p and q odd, p >= q
    else if (p >= q) return gcd((p-q) >> 1, q);

    // p and q odd, p < q
    else return gcd(p, (q-p) >> 1);
}

 static long gcd_fast(long x, long y) {
    while (x * y != 0) {
        if (x >= y) x = x % y;
        else y = y % x;
    }
    return (x + y);
}

    public static void main(String [] args)
    {
        long n, i, mod_sum, denominator, loop_prune, remainder, divi;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext())
        {
            n = scanner.nextLong();
            denominator = n * n;
            mod_sum = 0;
            loop_prune = n / 2;

            for(i = 2; i <= loop_prune; ++i)
                mod_sum += n % i;

            // from (n / 2) + 1, the remainders will form an arithmetic progression
            // this value can be calculated effortlessly using a closed formula
            remainder = n % (loop_prune + 1);
            mod_sum += remainder > 1 ? ((1 + remainder) * remainder) / 2 : remainder;
            divi = gcd_fast(denominator, mod_sum);
            System.out.printf("%d/%d\n", mod_sum / divi, denominator / divi);
        }

    }

}

