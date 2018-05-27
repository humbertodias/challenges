import java.util.*;

class Main{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int C = Integer.parseInt(scanner.nextLine());
        for(int i=0; i< C; i++){
			System.out.printf("%.2f\n", (scanner.nextLine().length()/100F) ) ;            	
        }
    }
}