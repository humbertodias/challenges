import java.util.*;
class Main{
	public static void main(String []args) {
	    int n = new Scanner(System.in).nextInt();
	    for (int i = 0; i < n; i++) {
	        System.out.print("Ho");
	        if (i < n - 1) System.out.print(" ");
	    }
	    System.out.println("!");
	}
}