import java.util.*;
class Main{
	public static void main(String []args){
		final double pi = Math.atan(1.0)*4.0;
	    double f, senos;
	    senos = Math.sin((108*pi)/180) / Math.sin((63*pi)/180);
	    Scanner scanner = new Scanner(System.in);
	    while(scanner.hasNext()){
	    	f = scanner.nextDouble();
	    	System.out.printf("%.10f\n",senos*f);
	    }
	}
}