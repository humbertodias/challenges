import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);

	    float x1 = scanner.nextFloat();
	    float y1 = scanner.nextFloat();
	    float x2 = scanner.nextFloat();
	    float y2 = scanner.nextFloat();

	    System.out.format("%.4f\n", Math.sqrt(Math.pow( (x2-x1),2) + Math.pow( (y2-y1),2)));
	}	
}
