import java.io.*;
import java.util.*;

public class Main {
  public static void main(String [] args) throws Exception {
    Scanner in = new Scanner(System.in);
    int n;
    while( (n = in.nextInt()) > 0) {
      int [] call_times = new int[n];
      int [] year = new int[n];
      char [] wanted = new char[n];
      for (int i=0; i<n; i++) {
        String s = in.next();
        int v = 0;
        for (int j=0; j<s.length(); j++)
          if (s.charAt(j) != ':')
            v = v*10 + (int)(s.charAt(j)-'0');
        call_times[i] = v;
        in.next(); // ignore number
        wanted[i] = in.next().charAt(0);
      }
      // recovery of years (how many years back each call is dated)
      year[n-1] = 0;
      for (int i=n-2; i>=0; i--) {
        year[i] = year[i+1];
        if (call_times[i] >= call_times[i+1])
          year[i]++;
      }
      int [] dp = new int[n];
      boolean lastplus = false;
      for (int i=n-1; i>=0; i--) {
        // calculate minimum number of calls to keep from the last n-i phone calls if we keep phone call i
        dp[i] = n-i; // first assume we need all phone calls
        if (year[i] == 0 && !lastplus)
          dp[i] = 1;
        if (wanted[i] == '+')
          lastplus = true;
        for (int j=i+1; j<n && year[i]-year[j] <= 1; j++) { // find a phone call to keep which is at most 1 year later

          // same year?
          if (year[j] == year[i]) { // delete all phone calls i+1 to j-1 and keep phone call j
            dp[i] = Math.min(dp[i],dp[j] + 1); // refer to the best result starting with phone call j
          }
          else { // next year
            if (call_times[j] > call_times[i]) { // would look like the same year
              break;
            }
            dp[i] = Math.min(dp[i],dp[j] + 1);
          }
          if (wanted[j] == '+')
            break;
        }
      }
      // find first phone call which has to be kept
      int result = -1;
      for (int i=0; i<n; i++)
        if (wanted[i] == '+') {
          result = dp[i];
          break;
        }
      System.out.println(result);
    }
  }
}