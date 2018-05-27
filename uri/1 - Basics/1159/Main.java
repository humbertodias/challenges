import java.util.*;
class Main{
	public static void main(String []args){
	    int x, s, i;
	    Scanner scanner = new Scanner(System.in);
	    x = scanner.nextInt();
	    while (x != 0){
	        s = 0;

	        if (x % 2 != 0) x++;

	        for (i = 0; i <= 4; i++, x += 2) s += x;

	        System.out.println(s);

	    	if(scanner.hasNextInt())
			    x = scanner.nextInt();
	    }
	}
}