import java.io.IOException;
import java.util.Scanner;

public class Main{

	public static void main(String ... args) throws IOException{
	    double f1, f2, f3;
	    String name;
	    Scanner scanner = new Scanner(System.in);
	    name = scanner.nextLine();
	    f1 = scanner.nextFloat();
	    f2 = scanner.nextFloat();
	    f3 = f1 + (15.0*f2/100.0);
	    System.out.format("TOTAL = R$ %.2f\n",f3);
	}
}