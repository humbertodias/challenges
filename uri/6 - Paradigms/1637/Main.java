// Algorithm: Dynamic Programming
// Complexity: O(n^3)

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String [] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int [] c = new int[128];
    int [][] dp = new int[129][129];
    int n;
    while((n = sc.nextInt()) != 0) {
      for (int i=0; i<n; ++i)
        c[i] = sc.nextInt();
      for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<=i+1; ++j)
          dp[i+1][j] = Integer.MAX_VALUE;
        for (int j=i; j>=0; --j) {
          sum += c[j];
          for (int k=(j>0?1:0); k<=j; ++k)
            dp[i+1][k+1] = Math.min(dp[i+1][k+1], dp[j][k] + sum * (k+i+2));
        }
      }
      int opt = Integer.MAX_VALUE;
      for (int i=1; i<=n; ++i)
        opt = Math.min(opt, dp[n][i]);
      System.out.println(opt);
    }
  }
}