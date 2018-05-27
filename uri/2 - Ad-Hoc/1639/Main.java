import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a;
        int [] occ = new int[10000];
        int tc = 1;
        while((a = sc.nextInt()) != 0){
            int res = 0;
            while(occ[a] != tc){
                occ[a] = tc;
                a = ((a*a)/100)%10000;
                ++res;
            }
            System.out.println(res);
            ++tc;
        }
    }
}