import java.util.*;

public class Main {

    static String hexToAscii(String s) {
      int n = s.length();
      StringBuilder sb = new StringBuilder(n / 2);
      for (int i = 0; i < n; i += 2) {
        char a = s.charAt(i);
        char b = s.charAt(i + 1);
        sb.append((char) ((hexToInt(a) << 4) | hexToInt(b)));
      }
      return sb.toString();
    }    

    static int hexToInt(char ch) {
      if ('a' <= ch && ch <= 'f') { return ch - 'a' + 10; }
      if ('A' <= ch && ch <= 'F') { return ch - 'A' + 10; }
      if ('0' <= ch && ch <= '9') { return ch - '0'; }
      throw new IllegalArgumentException(String.valueOf(ch));
    }

    public static void main(String[] args) {
        StringBuilder line = new StringBuilder();
        int n;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {   
            n = in.nextInt();
            for(int i=0; i< n && in.hasNext();i++)
            line.append(in.next());
            System.out.println( hexToAscii(line.toString()) );
            line.setLength(0);
        }       
    }
}