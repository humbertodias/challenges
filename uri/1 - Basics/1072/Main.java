import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int in = 0;
        int out = 0;
        int x = scanner.nextInt();
        for(int i = 0, a; i < x; i++){
            a = scanner.nextInt();
            if(a >= 10 && a <= 20) in++;
            else out++;
        }
        System.out.printf("%d in\n", in);
        System.out.printf("%d out\n", out);
    }
}