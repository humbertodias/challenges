import java.util.*;
class Main{
	public static void main(String []args){
	    int n = new Scanner(System.in).nextInt();
	    for(int i = 1; i <= n; i++){
		    System.out.printf("%d %d %d\n", i, i*i , i*i*i);
		    System.out.printf("%d %d %d\n", i, i*i+1,i*i*i+1);
	    }
	}
}