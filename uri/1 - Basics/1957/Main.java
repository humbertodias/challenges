import java.util.*;
class Main{

	public static void main(String []args){
		 Scanner scanner = new Scanner(System.in);
	     while(scanner.hasNext())
	     System.out.println(Long.toHexString(scanner.nextLong()).toUpperCase());
	}

}