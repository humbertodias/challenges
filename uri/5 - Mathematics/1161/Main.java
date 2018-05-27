import java.io.*;
import java.util.*;
 
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {
 
    public static long fatorial(int N)
    {
        long multi = 1;
        for (int i = 1; i <= N; i++) {
            multi = multi * i;
        }
        return multi;
    }

    public static void main(String[] args) throws IOException {
 
        /**
         * Escreva a sua solução aqui
         * Code your solution here
         * Escriba su solución aquí
         */
        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNextLine())
        {
            String line = scanner.nextLine();
            if( line.isEmpty() ) break;
            String [] nums = line.split(" ");
            int a = Integer.parseInt(nums[0]);
            int b = Integer.parseInt(nums[1]);
            System.out.println(fatorial(a) + fatorial(b));
        } 
    }
 
}
