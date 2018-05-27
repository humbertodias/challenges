import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        int n;
        Scanner in = new Scanner(System.in);
        while((n = in.nextInt()) != 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            long x = 0;
            HashMap<Integer,Integer> visit = new HashMap<Integer,Integer>();
            int c = 0;
            while(true) {
                ++c;
                if (visit.get((int)x) != null) {
                    int t = visit.get((int)x);
                    System.out.println(n-(c-t));
                    break;
                }
                visit.put((int)x,c);
                x = ((((x*x)%n)*a)%n+b)%n;
            }
        }
    }
}