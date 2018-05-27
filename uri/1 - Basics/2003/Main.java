import java.util.*;
class Main{
	public static void main(String []args)  
	{  
	    int a,b;  
	    Scanner scanner = new Scanner(System.in);
	    String line;
	    String parts[];
	    while(scanner.hasNext())  
	    {   parts = scanner.nextLine().split(":");
	    	a = Integer.parseInt(parts[0]);
	    	b = Integer.parseInt(parts[1]);
	        System.out.printf("Atraso maximo: ");  
	        if(a<7 || (a==7 && b==0)) System.out.printf("0\n");  
	        else System.out.printf("%d\n", ((a+1)-8)*60 + b);  
	    }  
	}  
}