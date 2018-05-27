import java.io.*;
import java.util.*;

public class Main {
   public static void main(String [] args) throws Exception {
      Scanner in = new Scanner(System.in);
      int tc = in.nextInt();
      int [] fibs = new int[21];
      fibs[0] = 1;
      fibs[1] = 2;
      for (int i=2; i<21; ++i)
         fibs[i] = fibs[i-1] + fibs[i-2];
      while(tc-- > 0) {
         int num = in.nextInt();
         int res = 0;
         for (int i=20; num > 0 && i>0; --i)
            if (fibs[i] <= num) {
               num -= fibs[i];
               res += fibs[i-1];
            }
         System.out.println(res);
      }
   }
}