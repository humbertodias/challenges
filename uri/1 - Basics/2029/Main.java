import java.util.*;
import java.math.*;

class Main{  
    static final double PI = 3.14f;

    static double round(Double d, int scale){
        return BigDecimal.valueOf(d).setScale(scale, RoundingMode.HALF_DOWN).doubleValue();
    }

    public static void main(String []args) {
     double v,d,alt,area;
     Scanner scanner = new Scanner(System.in);
      while(scanner.hasNext()){
        v = scanner.nextDouble();
        d = scanner.nextDouble();
        area = 3.14 * (d/2.0) * (d/2.0);
        alt = v / area;
     
        System.out.printf("ALTURA = %.2f\nAREA = %.2f\n"
            ,round(alt,2)
            ,round(area,2) ) ;
      }
    }

}  