import java.util.*;
class Main{
	public static void main(String [] args){
	    int x = new Scanner(System.in).nextInt();
	    for(int i = x, j=0; j < 6; i++){
	        if(i%2 != 0){
	           System.out.printf("%d\n",i);
	           j++;
	        }
	    }
	}
}