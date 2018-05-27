import java.util.*;

class Main{

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();


	// dois créditos são iguais 
    // ou um crédito é igual à soma dos outros dois. 
	// Com apenas alguns comandos if a solução fica com complexidade O(1).

	   int somaAC = a + c;
	   int somaAB = a + b;
	   int somaCB = c + b;

	   if (a == c || a == b || c == b)
	      System.out.println("S");
	   else if (somaAC == b || somaAB == c || somaCB == a)
	      System.out.println("S");
       else
	      System.out.println("N");


    }


}