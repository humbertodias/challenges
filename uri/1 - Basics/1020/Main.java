import java.util.*;

class Main{
	public static void main(String [] args){
	    Scanner scanner = new Scanner(System.in);
	    int a = scanner.nextInt();
	    System.out.println( a/365 + " ano(s)" );
	    System.out.println( (a%365)/30 + " mes(es)");
	    System.out.println( (a%365)%30 + " dia(s)");
	}
}