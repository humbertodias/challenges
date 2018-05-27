import java.util.*;
class Main{
	public static void main(String []args){
	    Scanner scanner = new Scanner(System.in);
	    int x, y;
	    
	    while(true){

		   x = scanner.nextInt();
		   y = scanner.nextInt();

		   if(x == 0 || y == 0) break;
		   
		   if(y > 0 && x > 0) System.out.println("primeiro");
		   if(y > 0 && x < 0) System.out.println("segundo");
		   if(y < 0 && x < 0) System.out.println("terceiro");
		   if(y < 0 && x > 0) System.out.println("quarto"); 
	               
	    }
	    
	}
}