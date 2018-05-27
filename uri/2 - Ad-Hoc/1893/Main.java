import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String phase = "";
        int i = scanner.nextInt();
        int f = scanner.nextInt();

        // Se a porção visível da lua no momento estiver 
        // entre 0 e 2%, por exemplo, é lua nova
        // se for entre 3 e 96% é lua crescente
        // se for entre 97 e 100% é lua cheia
        // se for entre 96 e 3% (diminuindo) é lua minguante.

        // A entrada é composta por uma única linha contendo dois valores inteiros. 
        // O primeiro valor corresponde ao percentual observado por Jade na noite de dois dias atrás. 
        // O segundo valor corresponde ao percentual observado por jade na noite anterior.

	    if( 3 <= f && f <= 96 && f > i ) phase = "crescente";
	    else if( 3 <= f && f <= 96 && f < i ) phase = "minguante";
	    else if( 0 <= f && f <= 2 ) phase =  "nova" ; 
	    else if( 97 <= f && f <= 100 ) phase = "cheia";

        System.out.println(phase);
    }
 
}