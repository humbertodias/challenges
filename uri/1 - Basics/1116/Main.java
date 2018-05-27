import java.util.*;
class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        int x, y, z, i;
        x = scanner.nextInt();
        
        for(i = 0; i < x; i++){
            y = scanner.nextInt();
            z = scanner.nextInt();
              
            if(z == 0){
               System.out.printf("divisao impossivel\n");
            } else{
               System.out.printf("%.1f\n", (float)y/(float)z);
            }
        }
        
    }
}