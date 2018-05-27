import java.util.*;
class Main{
	public static void main(String []args) {
	    int n, r1, r2;
	    Scanner scanner = new Scanner(System.in);
	    n = scanner.nextInt();
	    while (n-- > 0) {
	    	r1 = scanner.nextInt();
	    	r2 = scanner.nextInt();
	        System.out.printf("%d\n", r1 + r2);
	    }
	}
}