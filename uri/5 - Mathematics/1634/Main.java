import java.io.*;
import java.util.*;

public class Main {
    static int gcd(int a, int b) {
        return b != 0? gcd(b, a%b) : a;
    }
    public static void main(String [] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n, m;
        int [] a = new int[10000];
        while((n = sc.nextInt()) != 0 && (m = sc.nextInt()) != 0) {
            int sum = 0;
            for (int i=0; i<n; ++i) {
                for (int j=0; j<m; ++j)
                    a[i] = sc.nextInt();
                sum += a[i];
            }
            for (int i=0; i<n; ++i) {
                int t = gcd(a[i], sum);
                System.out.println(a[i]/t + " / " + sum/t);
            }
        }
    }
}