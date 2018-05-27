import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        BigInteger A;
         do{
            A = new BigInteger(scanner.nextLine().trim());
            System.out.format("%s\n", A.toString(32).toUpperCase() );
         }while ( !A.equals(0) && scanner.hasNext() );
    }
 
}
