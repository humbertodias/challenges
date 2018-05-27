import java.util.*;
class Main{
	public static void main(String []args){
	    int i, j = 0;
	    int n = new Scanner(System.in).nextInt();
	    for (i = 0; i < 1000; i++){
	        if (j >= n)
	            j = 0;
	        System.out.printf("N[%d] = %d\n", i, j++);
	    }
	}
}