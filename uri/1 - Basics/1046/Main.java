import java.util.*;

class Main{
	public static void main(String [] args){
	    Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();	    
	    
	    if(a >= b)
	        System.out.printf("O JOGO DUROU %d HORA(S)\n", (24 - a) + b);
	    else
	        System.out.printf("O JOGO DUROU %d HORA(S)\n", b - a);

	}
}