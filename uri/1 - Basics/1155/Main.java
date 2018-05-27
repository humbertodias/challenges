import java.util.*;
class Main{
	public static void main(String []args){
	    double s = 1.0f;
	    for (int i = 2; i <= 100; i++){
	        s += 1.0f / (double) i;
	    }
	    System.out.printf("%.2f\n", s);
	}
}