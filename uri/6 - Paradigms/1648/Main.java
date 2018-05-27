import java.io.*;
import java.util.*;
import java.text.*;

public class Main {
   public static void main(String [] args) throws Exception {
      Scanner in = new Scanner(System.in);
      DecimalFormat df = new DecimalFormat("0.0000", new DecimalFormatSymbols(Locale.US));
      while(true) {
         int n = in.nextInt();
         if (n == 0)
            break;
         int [] p = new int[n];
         int [] a = new int[n];
         int [][] perc = new int[n][n];
         for (int i=0; i<n; ++i) {
            p[i] = in.nextInt();
            a[i] = in.nextInt();
            int m = in.nextInt();
            for (int j=0; j<n; ++j)
               perc[i][j] = 0;
            while(m-- > 0) {
               int x = in.nextInt() - 1;
               perc[i][x] = in.nextInt();
            }
         }
         double best = 1e27;
         int N = 1 << n;
         double [] dp = new double[N];
         dp[0] = 0;
         for (int i=1; i<N; ++i)
            dp[i] = 1e27;
         for (int mask=0; mask < N; ++mask) {
            int area = 0;
            for (int i=0; i<n; ++i) {
               if ((mask & (1<<i)) > 0) {
                  area += a[i];
                  continue;
               }
               double r = 1;
               for (int j=0; j<n; ++j) {
                  if ((mask & (1<<j)) > 0)
                     r *= 1.0 - 0.01*perc[j][i];
               }
               dp[mask | (1<<i)] = Math.min(dp[mask | (1<<i)], dp[mask] + r * p[i]);
            }
            if (mask > 0)
               best = Math.min(best, dp[mask] / area);
         }
         System.out.println(df.format(best));
      }
   }
}