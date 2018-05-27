import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        Scanner in = new Scanner(System.in);
        while(true) {
            int c = in.nextInt();
            int n = in.nextInt();
            if (c == 0 && n == 0)
                break;
            int [] ind = new int[c];
            Arrays.fill(ind,-1);
            int sum = 0;
            ind[0] = 0;
            for (int i=0; i<n; ++i) {
                int a = in.nextInt();
                sum = (sum+a)%c;
                if (ind[sum] >= 0) {
                    for (int j=ind[sum]; j<=i; ++j) {
                        System.out.print(j+1);
                        if (j<i) System.out.print(" ");
                    }
                    System.out.println("");
                    for (i++; i<n; ++i)
                        a = in.nextInt();
                    break;
                }
                ind[sum] = i+1;
            }
        }
    }
}