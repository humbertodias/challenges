import java.util.*;

class Main{

	static String lpad(int n){
		if(n<10) return "0" + n;
		return ""+n;
	}

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int H,M,O; 
        for(int i=0; i< N; i++){
        	H = scanner.nextInt();
        	M = scanner.nextInt();
        	O = scanner.nextInt();
			System.out.printf("%s:%s - A porta %s!\n", lpad(H),lpad(M), (O==1?"abriu":"fechou") ) ;            	
        }
    }
}