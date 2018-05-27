import java.util.*;

public class Main{

	public static void main(String args[]){
	    Scanner scanner = new Scanner(System.in);

	    int a = scanner.nextInt();
	    int b = scanner.nextInt();
	    float f = (a*b)/12.0f;

	    System.out.format("%.3f\n", f);
	}

}
