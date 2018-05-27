import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

    static long [] fatorial = new long[1000001];

    public static void main(String[] args) {

    int n, i, c;

    fatorial[0] = fatorial[1] = 1;
    for (i = 2; i < 1000001; i++) {
        long fat = i * fatorial[i-1];
        while (fat % 10==0) { /*ignora os digitos finais = 0*/
            fat /= 10;
        }
        fat = fat % 10000000; /*guarda os digitos finais*/
        fatorial[i] = fat;
    }

        Scanner in = new Scanner(System.in);
        c = 1;
        while(in.hasNext()) {
            n = in.nextInt();
            System.out.printf("Instancia %d\n%d\n\n", c, fatorial[n]%10);
            c++;
        }
    }

}