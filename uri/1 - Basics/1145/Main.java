import java.util.*;
class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        int n=1;
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        for(int i = 1; i <= y; i++){
            if(n == x) {
             System.out.printf("%d\n", i);
             n = 1;
            }
            else{
    	        System.out.printf("%d ", i);
    	        n++;
            }
        }

    }
}