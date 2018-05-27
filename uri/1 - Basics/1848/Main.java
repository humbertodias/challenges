import java.util.*;

class Main{
    public static void main(String []args) {
      Scanner scanner = new Scanner(System.in);
      int acc = 0;
      String line;
      while (scanner.hasNext()) {
        line = scanner.next();
        if (line.equals("caw")) {
            line = scanner.next();
          System.out.printf("%d\n", acc);
          acc = 0;
        } else {
          int val = 0;
          for (int i = 0; i < 3; ++i) {
            val <<= 1;
            val += line.charAt(i) == '*' ? 1 : 0;
          }
          acc += val;
        }
      }
    }
}