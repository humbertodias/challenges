import java.util.*;
class Main{
	public static void main(String []args) {
		
		double a, r=0, aux = 0;
		Scanner scanner = new Scanner(System.in);
		while ( scanner.hasNext() ){
			a = scanner.nextDouble();
			if (a==3) System.out.printf("0\n") ;
			else if (a==4) System.out.printf("2\n");
			else{   
			   r=0; aux=0;
			   for (double i=2; i<a-1; i++){
			      r=aux+i;
			      aux=r;   // se digitar 5 = 5; 6 = 9; 7 =14; 2+3+4+5+6...
			   }
			System.out.printf("%.0f\n", aux);
			}

		}

	}
}