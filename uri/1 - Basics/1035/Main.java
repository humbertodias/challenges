import java.util.*;

class Main{
	public static void main(String args[]){
	    Scanner scanner = new Scanner(System.in);
	    int a = scanner.nextInt();
	    int b = scanner.nextInt();
	    int c = scanner.nextInt();
	    int d = scanner.nextInt();
	    
	    if(b > c && d > a && (c+d) > (a+b) && c > 0 && d > 0 && a%2 == 0)
	        System.out.format("Valores aceitos\n");
	    else
	        System.out.format("Valores nao aceitos\n");

	}
}
