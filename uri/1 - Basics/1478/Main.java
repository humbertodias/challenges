import java.util.*;
import java.io.*;
class Main{

  public static void main (String []args) throws Exception {
      int n = 0, i, j;
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in), 512);
      PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out), false);
      String line;
      while ( (line = in.readLine()) != null && !"0".equals(line)) {
          n = Integer.parseInt(line);
          for (i = 0; i < n; i++) {
              for (j = 0; j < n; j++) {
                  out.printf("%3d", Math.abs(j-i)+1);
                  if (j != n-1) out.printf(" ");
              }
              out.printf("\n");
          }
          out.printf("\n");
          out.flush();
      }
      in.close();
      out.close();
  }

}