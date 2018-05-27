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

        float a,b,c;
        float mod1, mod2, mod3;

        a = scanner.nextFloat();
        b = scanner.nextFloat();
        c = scanner.nextFloat();

        mod1 = Math.abs(c - b);
        mod2 = Math.abs(a - b);
        mod3 = Math.abs(a - c);

        if (mod1 < a && a < (b + c) && mod2 < c && c < (a+b) && mod3 < b && b < (a+c))
            System.out.format("Perimetro = %.1f\n", a+b+c);
        else
            System.out.format("Area = %.1f\n", ((a+b)*c)/2.0 );

    }
 
}
