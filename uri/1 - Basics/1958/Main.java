import java.util.*;
class Main{

	public static void main(String []args){
		// Upper = E
		// + sign
		// .4 precision
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			System.out.printf("%+.4E\n", scanner.nextDouble() );
		}
	}

}