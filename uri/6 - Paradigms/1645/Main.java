/* 
* Complexity: O(n^3)
* Algorithm: Dynamic Programming
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        Scanner in = new Scanner(System.in);
        while(true) {
            int n = in.nextInt();
            int k = in.nextInt();
            if (n == 0 && k == 0)
                break;
            long ans = 0;
            int [] a = new int[n];
            long [][] dp = new long[n][n];
            for (int i=0; i<n; ++i) {
                a[i] = in.nextInt();
                dp[i][0] = 1;
                for (int j=1; j<k; ++j) {
                    dp[i][j] = 0;
                    for (int ii=0; ii<i; ++ii) {
                        if (a[ii] >= a[i])
                            continue;
                        dp[i][j] += dp[ii][j-1];
                    }
                }
                ans += dp[i][k-1];
            }
            System.out.println(ans);
        }
    }
}