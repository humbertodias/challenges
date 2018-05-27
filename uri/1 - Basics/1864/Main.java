import java.util.*;
class Main{

	public static void main(String []args){

	    final char[] QUOTE = "LIFE IS NOT A PROBLEM TO BE SOLVED".toCharArray();

	    int N = new Scanner(System.in).nextInt();

	    for(int i = 0; i < N; i++)
	        System.out.printf("%c", QUOTE[i] );

	    System.out.printf("\n");

	}

}