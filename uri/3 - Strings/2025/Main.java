import java.util.*;

class Main{
	
	public static void main(String[] args){
		int n;
		String s;
		
		Scanner input = new Scanner(System.in);
	
		n = input.nextInt();
		
		for(int j = 0; j <= n; j++){
			s = input.nextLine();
			
			String[] arr = s.split(" ");
			
			for(int i = 0; i < arr.length; i++){
				if(i > 0){
					System.out.print(" ");
				}
				if(arr[i].contains("oulupukk")){
					System.out.print("Joulupukki");
					if(arr[i].contains(".")){
						System.out.print(".");
					}
				}else{
					System.out.print(arr[i]);
				}
			}
			if(j>0)
			System.out.println();
		}
	}
}