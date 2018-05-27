import java.util.*;
class Main{
    public static void main(String []args) {

        Locale.setDefault( Locale.US );
        Scanner scanner = new Scanner(System.in);

        final double M_PI=3.14159265358979323846;
        double x, A, B, C, a, b, c, sq3 = Math.sqrt(3.);


        while( scanner.hasNext() ) {
            x = scanner.nextDouble();

            A = (M_PI / 2. - 1.) * x * x;
            B = (M_PI / 3. - sq3 / 4.) * x * x;
            C = x * x;
            c = B - A;
            b = (C - A - 4*c) / 2;
            a = A - 2 * b;
            System.out.printf("%.3f %.3f %.3f\n", a, 4 * b, 4 * c);


        }

    }
}