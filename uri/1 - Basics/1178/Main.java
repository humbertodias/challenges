import java.util.*;
import java.math.*;
class Main{

	public static double round(double value, int places) {
	    if (places < 0) throw new IllegalArgumentException();
	    BigDecimal bd = new BigDecimal(value);
	    bd = bd.setScale(places, RoundingMode.HALF_DOWN);
	    return bd.doubleValue();
	}

	public static void main(String []args){
	    double n = new Scanner(System.in).nextDouble();
	    for (int i = 0; i <= 99; i++){
	        System.out.printf("N[%d] = %.4f\n", i, round(n,4) );
	        n /= 2;
	    }
	}
}