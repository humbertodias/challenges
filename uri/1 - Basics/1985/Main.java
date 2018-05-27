import java.util.*;
class Main{
  public static void main(String []args) {
      int p, q;
      float t = 0;
      Scanner scanner = new Scanner(System.in);
      int n = scanner.nextInt();
      while(n-- > 0) {
          p = scanner.nextInt();
          q = scanner.nextInt();
          if(p == 1001) t += (1.5 * q);
          else if(p == 1002) t += (2.5 * q);
          else if(p == 1003) t += (3.5 * q);
          else if(p == 1004) t += (4.5 * q);
          else t += (5.5 * q);
      }

      System.out.printf("%.2f\n", t);
  }
}