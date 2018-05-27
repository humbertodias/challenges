import java.util.*;
class Main{
	public static void main(String args[]){
	    Scanner scanner = new Scanner(System.in);
	    int i, x, y, aux;
	    int soma;
	    int n = scanner.nextInt();
	    
	    while(true){
		    if(n == 0) break;
		    x = scanner.nextInt();
		    y = scanner.nextInt();
		    
		    if(x > y){
		         aux = x;
		         x = y;
		         y = aux;
		    }
		    soma = 0;
		    for(i = x+1; i < y; i++){
		           if(i%2 != 0) soma += i;
		    }
		    System.out.println(soma);
		    n--;
	    }

	}
}