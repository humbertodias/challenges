import java.util.*;

public class Main{

	public static void main(String args[]){
	    Scanner scanner = new Scanner(System.in);
	    double a = scanner.nextDouble();
	    double b = scanner.nextDouble();
	    double c = scanner.nextDouble();
	    double pi = 3.14159;
	    
	    System.out.format("TRIANGULO: %.3f\n", (a*c)/2.0);
	    System.out.format("CIRCULO: %.3f\n", pi*c*c);
	    System.out.format("TRAPEZIO: %.3f\n", ((a+b)*c)/2.0);
	    System.out.format("QUADRADO: %.3f\n", b*b);
	    System.out.format("RETANGULO: %.3f\n", a*b);

	}

}
