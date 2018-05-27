import java.util.*;
class Main{
	public static void main(String []args){
	    int r1,x1,y1,r2,x2,y2;
	    double distancia;
	    Scanner scanner = new Scanner(System.in);
	    while(scanner.hasNext()){
	    	r1 = scanner.nextInt();
	    	x1 = scanner.nextInt();
	    	y1 = scanner.nextInt();
	    	
	    	r2 = scanner.nextInt();
	    	x2 = scanner.nextInt();
	    	y2 = scanner.nextInt();
	    	
	    	distancia = Math.sqrt(Math.pow(x2-x1,2) + Math.pow(y2-y1,2));
	        if(r1 >= distancia+r2) System.out.printf("RICO\n");
	        else System.out.printf("MORTO\n");
	    }
	}
}