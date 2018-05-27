import java.util.*;
class Main{
	public static void main(String [] args){
	    long n, m;
		Scanner scanner = new Scanner(System.in);
	    while(scanner.hasNext()){
	    	n = scanner.nextLong();
	    	m = scanner.nextLong();
	        System.out.printf("%d\n", n ^ m);
	    }
	}
}