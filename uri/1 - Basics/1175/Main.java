import java.util.*;
class Main{
	public static void main(String []args){
		Scanner scanner = new Scanner(System.in);
	    int x, i;
	    int a[] = new int[20];
	    for (i = 0; i <= 19; i++) {
	    	a[i] = scanner.nextInt();
	    }

	    for (i = 0; i <= 9; i++){
	        x = a[i];
	        a[i] = a[19 - i];
	        a[19 - i] = x;
	    }

	    for (i = 0; i <= 19; i++) System.out.printf("N[%d] = %d\n", i, a[i]);
	}
}