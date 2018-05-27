import java.util.*;
class Main{
	static int fat(int n){
	    if (n == 0 || n == 1) return 1;
	    return n * fat(n - 1);
	}
	public static void main(String []args){
	    int n = new Scanner(System.in).nextInt();
	    System.out.printf("%d\n", fat(n));
	}
}