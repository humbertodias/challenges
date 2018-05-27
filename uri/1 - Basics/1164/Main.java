import java.io.*;
import java.util.*;

class Main {

    static long divisor_sum( long number ) { 
       long sum = 0, i ; 
       for (i = 1 ; i < number ; i++ ) 
          if ( number % i == 0 ) 
             sum += i ; 
       return sum; 
    }
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        for(int i = 0, num = 0; i < n; i++){
            num = scanner.nextInt();

            if(divisor_sum(num) == num) System.out.format("%d eh perfeito\n", num);
            else System.out.format("%d nao eh perfeito\n", num);

        }
    }
 
}
