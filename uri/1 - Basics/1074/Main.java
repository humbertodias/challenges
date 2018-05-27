import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        for(int i = 0, a; i < x; i++){
            a = scanner.nextInt();
            if(a == 0){
                 System.out.printf("NULL\n");
            }
            else{
                if(a%2 == 0) System.out.printf("EVEN");
                else System.out.printf("ODD");
                
                if(a<0) System.out.printf(" NEGATIVE\n");
                else System.out.printf(" POSITIVE\n");
            }
        }
        
    }
}