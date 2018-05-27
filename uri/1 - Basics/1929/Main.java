import java.io.IOException;
import java.util.Scanner;
 
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {
 
    public static void main(String[] args) throws IOException {
 
        /**
         * Escreva a sua solução aqui
         * Code your solution here
         * Escriba su solución aquí
         */
        Scanner scanner = new Scanner(System.in);
        String[] abcd = scanner.nextLine().split(" ");
        int a = Integer.parseInt(abcd[0]);
        int b = Integer.parseInt(abcd[1]);
        int c = Integer.parseInt(abcd[2]);
        int d = Integer.parseInt(abcd[3]);

        boolean tenta1 = (Math.abs(b-c) < a && a < (b+c)) || (Math.abs(a-c) < b && b < (a+c)) || (Math.abs(a-b) < c && c < (a+b)); // a b c
        boolean tenta2 = (Math.abs(c-d) < b && b < (c+d)) || (Math.abs(b-d) < c && c < (b+d)) || (Math.abs(b-c) < d && d < (b+c)); // b c d
        boolean tenta3 = (Math.abs(c-d) < a && a < (c+d)) || (Math.abs(a-d) < c && c < (a+d)) || (Math.abs(a-c) < d && d < (a+c)); // a c d
        boolean tenta4 = (Math.abs(b-d) < a && a < (b+d)) || (Math.abs(a-d) < b && b < (a+d)) || (Math.abs(a-b) < d && d < (a+b)); // a b d
        
        if (tenta1 || tenta2 || tenta3 || tenta4) { // vê se é triangulo
            System.out.println("S");
        }
        else {
            System.out.println("N");
        } 
    }
 
}
