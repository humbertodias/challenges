import java.util.*;

class Main{

	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);

	    double a = scanner.nextDouble();
	    double b = scanner.nextDouble();
	    double c = scanner.nextDouble();

	    if((Math.pow(b,2) - 4*a*c) < 0 || 2*a == 0)
	         System.out.format("Impossivel calcular\n");
	    else{
	         System.out.format("R1 = %.5f\n",((-b) + Math.sqrt((Math.pow(b,2) - 4*a*c)))/(2*a));
	         System.out.format("R2 = %.5f\n",((-b) - Math.sqrt((Math.pow(b,2) - 4*a*c)))/(2*a));
	     }
	}

}