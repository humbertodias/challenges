import java.util.*;

class Main{

    static double binet(long n){
        double A = Math.pow( (1 + Math.sqrt(5))/2 , n);
        double B = Math.pow( (1 - Math.sqrt(5))/2 , n);
        return (A-B)/Math.sqrt(5);
    }

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
		System.out.printf("%.1f\n", binet(N) ) ;            	
    }
    
}