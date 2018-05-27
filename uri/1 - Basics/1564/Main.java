import java.util.*;
class Main{
	public static void main (String []args){
	    Scanner scanner = new Scanner(System.in);
	    while (scanner.hasNext()){
	        if (scanner.nextInt()>0) System.out.println("vai ter duas!");
	        else System.out.println("vai ter copa!");
	    }
	}
}