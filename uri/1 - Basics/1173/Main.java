import java.util.*;
class Main{
	public static void main(String []args){
	    int n = new Scanner(System.in).nextInt();
	    for (int i = 0; i < 10; i++){
	        System.out.printf("N[%d] = %d\n", i, n);
	        n *= 2;
	    }
	}
}