import java.util.*;
class Main{
	public static void main(String []args) {
	    double n,l;
	    Scanner scanner = new Scanner(System.in);
	    while (scanner.hasNext()) {
	    	n = scanner.nextDouble();
	    	l = scanner.nextDouble();
	        System.out.printf("%.0f\n", n*l);
	    }
	}
}