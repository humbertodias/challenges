import java.util.*;
class Main{
	public static void main(String [] args){
	    int n = new Scanner(System.in).nextInt();
	    for(int i = 1; i < 10000; i++){
	        if(i%n == 2)
	            System.out.printf("%d\n",i);
	    }
	}
}