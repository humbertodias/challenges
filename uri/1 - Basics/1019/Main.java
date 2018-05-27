import java.util.*;

class Main{
	public static void main(String [] args){
	    Scanner scanner = new Scanner(System.in);
	    int a = scanner.nextInt();
	    System.out.println( a/3600 +  ":" +  (a%3600)/60 +  ":" + a%60);
	}
}