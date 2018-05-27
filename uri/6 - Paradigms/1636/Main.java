// Algorithm:  Dynamic programming
// Complexity: O(n) time + space

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String [] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int [] p = new int[1000001];
    int [] ind = new int[1000001];
    int n;
    while((n = sc.nextInt()) != 0) {
      if (n == 1) {
        System.out.println("1");
        continue;
      }
      p[1] = 2;
      p[2] = 1;
      ind[1] = 2;
      ind[2] = 1;
      for (int i=4; i<=n; i+=2) {
        // find position of i/2
        int pos = ind[i/2];
        p[i-1] = i;
        p[i] = i/2;
        p[pos] = i-1;
        ind[i] = i-1;
        ind[i-1] = pos;
      }
      if (n%2 != 0) {
        int pos = ind[(n+1)/2];
        p[pos] = n;
        p[n] = (n+1)/2;
      }
      for (int i=1; i<=n; ++i) {
        if (i > 1)
          System.out.print(" ");
        System.out.print(p[i]);
      }
      System.out.println("");
    }
  }
}