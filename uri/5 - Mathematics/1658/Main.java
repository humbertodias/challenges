import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n;
        while( (n = in.nextInt()) != 0) {
            int sign = 1;
            int rotation = 0;
            while(!in.hasNextInt()) {
                String s = in.next();
                int v = Integer.parseInt(s.substring(1));
                if (s.charAt(0) == 'm') {
                    v %= 2;
                    if (v != 0)
                        sign = -sign;
                }
                else {
                    rotation += sign*v;
                    rotation %= n;
                }
            }
            if (rotation < 0)
                rotation += n;
            if (sign < 0) {
                if (n-rotation < rotation)
                    System.out.println("m1 r"+(n-rotation));
                else if (rotation > 0)
                    System.out.println("r"+rotation+" m1");
                else
                    System.out.println("m1");
            }
            else {
                if (n-rotation+2<rotation)
                    System.out.println("m1 r"+(n-rotation)+" m1");
                else
                    System.out.println(rotation>0?"r"+rotation:"");
            }
        }
    }
}