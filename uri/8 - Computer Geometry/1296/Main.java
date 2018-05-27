import java.util.*;
class Main{
   public static void main(String []args) {
      double m1, m2, m3, area, s, inner;
      Scanner scanner = new Scanner(System.in);
      while(scanner.hasNext()){
         m1 = scanner.nextDouble();
         m2 = scanner.nextDouble();
         m3 = scanner.nextDouble();

         s = (m1 + m2 + m3) / 2;
         inner = s * (s - m1) * (s - m2) * (s - m3);

         area = -1;
         if (inner > 0)
            area = 4.0 * Math.sqrt(inner) / 3.0;

         System.out.printf("%.3f\n", area);
      }
   }
}