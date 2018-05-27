import java.util.*;
class Main{
	public static void main(String [] args){
		Scanner scanner = new Scanner(System.in);
	    double a, b, c;
	    int n = scanner.nextInt();
	    for(int i = 0; i < n; i++){
	        a = scanner.nextDouble();
	        b = scanner.nextDouble();
	        c = scanner.nextDouble();
	        System.out.printf("%.1f\n", (a*2 + b*3 + c*5)/(2.0+3.0+5.0) );
	    }
	}
}