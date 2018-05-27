import java.util.*;
class Main{
	public static void main(String []args){
	    int a = new Scanner(System.in).nextInt();
	    for(int i = 0; i < a*4;){
	      System.out.printf("%d %d %d PUM\n", (i+1),(i+2),(i+3));
	      i+=4;
	    }
	}
}