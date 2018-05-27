import java.util.*;
class Main{
	public static void main(String []args){
	    int a, b, c;
	    double minimun_land_size;
	    Scanner scanner = new Scanner(System.in);
	    while (scanner.hasNextInt()){
	    	a = scanner.nextInt();
	    	if(a == 0) break;
	        b = scanner.nextInt();
	        c = scanner.nextInt();
	        minimun_land_size = (100 * a * b) / c;
	        System.out.printf("%.0f\n", Math.floor(Math.sqrt(minimun_land_size)) );
	    }

	}
}