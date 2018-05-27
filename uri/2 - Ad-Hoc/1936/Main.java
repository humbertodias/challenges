import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {

	static long uri1936( int N){
	long k=0;
	while (N>0) {
	   long b=1, bfat=1;
	   while (bfat <= N) {
	     b += 1;
	     bfat *= b;
	   }
	   k +=1;
	   N -= bfat / b;
	}
	return k;
	}
 
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.format("%d\n", uri1936(N) );
 
    }
 
}
