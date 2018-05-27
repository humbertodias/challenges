import java.util.*;
class Main{
	public static void main(String []args){
	    int a = new Scanner(System.in).nextInt();
	    for(int i = 0; i < a; i++){
	    	System.out.printf("%d %d %d\n",i+1, (int)Math.pow(i+1,2), (int)Math.pow(i+1,3));
		}
	}
}