import java.util.*;

public class Main{

	public static void main(String args[]){
	    Scanner scanner = new Scanner(System.in);
	    int a = scanner.nextInt();
	    float b = scanner.nextFloat();
	    
	    System.out.format("%.3f km/l\n", a/b);
	}	
	
}
