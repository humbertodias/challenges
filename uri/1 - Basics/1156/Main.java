import java.util.*;
class Main{
	public static void main(String []args){
	    double s = 1.0, x = 2.0;
	    for (int i = 3; i <= 39; i += 2){
	        s += (double) i / x;
	        x *= 2f;
	    }
	    System.out.printf("%.2f\n", s);
	}
}