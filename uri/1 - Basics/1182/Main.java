import java.util.*;
class Main{
    public static void main(String []args) {
        char o;
        int i, j, c;
        float s = 0.0f, n = 0;
        Scanner scanner = new Scanner(System.in);
        c = scanner.nextInt();
        o = scanner.next().charAt(0);

        for (i = 0; i <= 11; i++) {
            for (j = 0; j <= 11; j++) {
                if(scanner.hasNext())
                    n = scanner.nextFloat();
                if (j == c) s += n;
            }
        }

        if (o == 'S') System.out.printf("%.1f\n", s);
        else System.out.printf("%.1f\n", s / 12);
    }
}