import java.util.*;
class Main{
	public static void main(String []args){
		Scanner scanner = new Scanner(System.in);
	    int x, s = 0, z = 0, n = 0, i;
	    x = scanner.nextInt();
	    while(z <= x){
	    	z = scanner.nextInt();
		}
	    for (i = x; s <= z; i++){
	        s += x++;
	        n++;
	    }

	    System.out.printf("%d\n", n);
	}
}