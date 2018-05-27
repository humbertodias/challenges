import java.io.*;
import java.util.*;
 
class Main {

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);

        int n;
        for(int i = 0; i < 10; i++){
                try{
                    n = scanner.nextInt();
                }catch(Exception e){n=0;}
                if(n <= 0) n = 1;
                System.out.format("X[%d] = %d\n" ,i, n);
        }
    }
 
}
