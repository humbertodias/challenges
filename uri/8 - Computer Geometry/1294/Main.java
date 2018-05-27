import java.util.*;
class Main{
	public static void main(String []args) {
	    double l, w, delta, x;
	    Scanner scanner = new Scanner(System.in);
	    while(scanner.hasNext()){
	    	l = scanner.nextDouble();
	    	w = scanner.nextDouble();
	        delta = Math.sqrt( 16.0*( w + l )*( w + l ) - 48.0*w*l );
	        x = ( 4.0*( w + l ) - delta )/24.0;
	        System.out.printf( "%.3f 0.000 %.3f\n", x, w > l ? l/2.0 : w/2.0 );
	    }
	}
}