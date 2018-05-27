import java.util.*;
class Main{
	public static void main(String [] args){
	    int n = new Scanner(System.in).nextInt();
	    for(int i = 1; i <= 10; i++)
	    	System.out.printf("%d x %d = %d\n", i, n, n*i);
	}
}