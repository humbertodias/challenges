import java.util.*;
class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        int x, y, s, i;
        int n = scanner.nextInt();
        while (n-- > 0){
            s = 0;
            x = scanner.nextInt();
            y = scanner.nextInt();

            if (x % 2 == 0) x++;

            for (i = 0; i < y; i++, x += 2) s += x;

            System.out.println(s);
        }
    }
}