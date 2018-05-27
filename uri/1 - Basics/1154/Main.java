import java.util.*;
class Main{
	public static void main(String []args) {
	    float sum = 0.0f;
	    int count = 0;
	    Scanner scanner = new Scanner(System.in);
	    int n = scanner.nextInt();
	    while (n >= 0) {
	        sum += n;
	        count += 1;
	        n = scanner.nextInt();
	    }
	    System.out.printf("%.2f\n", sum / count);
	}
}