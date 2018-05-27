import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int par = 0;
        int a = scanner.nextInt();
        if(a%2 == 0){
             par++;
        }
        int b = scanner.nextInt();
        if(b%2 == 0){
             par++;
        }
        int c = scanner.nextInt();
        if(c%2 == 0){
             par++;
        }
        int d = scanner.nextInt();
        if(d%2 == 0){
             par++;
        }
        int e = scanner.nextInt();
        if(e%2 == 0){
             par++;
        }
        
        System.out.printf("%d valores pares\n", par);
    }
}