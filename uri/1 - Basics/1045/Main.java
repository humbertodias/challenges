import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);

        float a,b,c;
        a = scanner.nextFloat();
        b = scanner.nextFloat();
        c = scanner.nextFloat();

        if(a >= (b+c) || b >= (a+c) || c >= (a+b))
            System.out.format("NAO FORMA TRIANGULO\n");
        else if(a*a == (b*b + c*c) || b*b == (a*a + c*c) || c*c == (a*a + b*b))
            System.out.format("TRIANGULO RETANGULO\n");
        else if(a*a > (b*b + c*c) || b*b > (a*a + c*c) || c*c > (a*a + b*b))
            System.out.format("TRIANGULO OBTUSANGULO\n");
        else if(a*a < (b*b + c*c) || b*b < (a*a + c*c) || c*c < (a*a + b*b))
            System.out.format("TRIANGULO ACUTANGULO\n");
        if(a == b && a == c)
            System.out.format("TRIANGULO EQUILATERO\n");
        if((a == b && a != c)  || (a == c && a != b) || (b == c && b != a))
            System.out.format("TRIANGULO ISOSCELES\n");

    }
 
}
