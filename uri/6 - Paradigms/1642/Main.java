import java.util.*;
import java.io.*;

public class Main {
   public static void main(String... args) throws Exception {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      String line;
      while ((line = in.readLine()) != null) {
         int m = Integer.parseInt(line);
         if (m == 0) {
            break;
         }
         line = in.readLine();
         int start = 0, end = 0;
         int[] count = new int[256];
         int diff = 0;
         int best = 0;
         while (end < line.length()) {
            if (diff < m || count[line.charAt(end)] > 0) {
               if (count[line.charAt(end)] == 0) {
                  diff++;
               }
               count[line.charAt(end)]++;
               end++;
               if (end - start > best) {
                  best = end - start;
               }
            } else {
               count[line.charAt(start)]--;
               if (count[line.charAt(start)] == 0) {
                  diff--;
               }
               start++;
            }
         }
         System.out.println(best);
      }
      in.close();
   }
}