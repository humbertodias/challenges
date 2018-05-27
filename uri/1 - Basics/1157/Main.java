import java.util.*;
class Main{
	public static void main(String []args){
	    int n = new Scanner(System.in).nextInt();
	    for (int i = 1; i <= n / 2; i++){
	        if (n % i == 0)
	            System.out.printf("%d\n", i);
	    }
	    System.out.printf("%d\n", n);
	}
}