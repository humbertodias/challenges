import java.util.*;
class Main{
    public static void main(String []args){
        int a, b, c;
        float ac, bc;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        while (n-- > 0){
            c = 0;
            a = scanner.nextInt();
            b = scanner.nextInt();
            ac = scanner.nextFloat();
            bc = scanner.nextFloat();
            while(a <= b){
                a *= (ac / 100.0) + 1.0;
                b *= (bc / 100.0) + 1.0;
                c++;
                if (c > 100){
                    System.out.printf("Mais de 1 seculo.\n");
                    break;
                }
            }
            if (c <= 100)
                System.out.printf("%d anos.\n", c);
        }
    }
}