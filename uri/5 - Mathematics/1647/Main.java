import java.util.*;
import java.io.*;

public class Main {
	public static void main(String... args) throws Exception {
		Scanner s = new Scanner(System.in);
		
		int n;
		while ((n = s.nextInt()) > 0) {
			int data[] = new int[n];
			for (int i = 0; i < n; i++) {
				data[i] = s.nextInt();
			}

			long sum = 0;
			for (int i = n - 1; i >= 0; i--) {
				sum += sum + data[i];
			}
			System.out.println(sum);
		}	
	}
}