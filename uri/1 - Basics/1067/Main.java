import java.util.*;
class Main{
	public static void main(String [] args){
	    int x = new Scanner(System.in).nextInt();
	    for(int i = 1; i <=x; i++){
	        if(i%2 != 0)
	            System.out.printf("%d\n", i);
	    }
	}
}