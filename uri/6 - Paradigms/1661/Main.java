import java.io.*;
import java.util.*;

public class Main {
   public static void main(String [] args) throws Exception {
      Scanner in = new Scanner(System.in);
      int n;
      while( (n = in.nextInt()) > 0) {
         long sum = 0;
         long result = 0;
         for (int i=0; i<n; i++) {
            sum += in.nextInt();
            result += Math.abs(sum);
         }
         System.out.println(result);
      }
   }
}