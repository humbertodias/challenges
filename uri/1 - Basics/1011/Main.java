import java.util.*;

public class Main{

	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
	    int a = scanner.nextInt();
	    System.out.format("VOLUME = %.3f\n", (4.0/3.0)*3.14159* Math.pow(a,3));
	}

}
