import java.util.*;
class Main{
    public static void main(String []args){
        int a, b, x, i;
        int n = new Scanner(System.in).nextInt();
        if (n == 0){ System.out.printf("0\n"); }

        a = 1;
        b = 1;
        System.out.printf("0");
        for (i = 1; i < n; i++){
            System.out.printf(" %d", a);
            x = a;
            a = b;
            b = b + x;
        }
        System.out.printf("\n");
    }
}