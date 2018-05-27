import java.io.*;
import java.util.*;

public class Main{

	public static void main(String ... args) throws IOException{

		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		float e = sc.nextFloat();     

		int c = sc.nextInt();
		int d = sc.nextInt();
		float f = sc.nextFloat();     

		System.out.format("VALOR A PAGAR: R$ %.2f\n", (b*e + d*f) );
	}

}
