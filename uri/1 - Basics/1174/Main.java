import java.util.*;
class Main{
	public static void main(String []args){
	    int n = -1;
	    float i = 0;
	    Scanner scanner = new Scanner(System.in);
	    while (++n <= 99){
	    	if(scanner.hasNext())
	        i = scanner.nextFloat();
	        if (i <= 10){
	            System.out.printf("A[%d] = %.1f\n", n, i);
	        }
	    }
	}
}