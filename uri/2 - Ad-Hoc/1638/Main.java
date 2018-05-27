import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n;
        int [] requests = new int[101];
        int [] ps = new int[101];
        while((n = sc.nextInt()) != 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int total = 0;
            for (int i=1; i<=100; ++i)
                requests[i] = 0;
            for (int i=0; i<n; ++i) {
                int rsize = sc.nextInt();
                total += rsize;
                ++requests[rsize];
            }
            int max_size = 100;
            while(requests[max_size] == 0)
                --max_size;
            ps[0] = 0;
            for (int i=1; i<=max_size; ++i)
                ps[i] = ps[i-1] + requests[i];
            int best = Integer.MAX_VALUE;
            for (int d=1; d<=3; ++d) {
                for (int i=max_size; i * 3 >= max_size * d; --i) {
                    // biggest requested portion size which can be served as one portion
                    int p1 = i / d;
                    // biggest requested portion size which can be served as two portions
                    int p2 = Math.min(i * 2 / d, max_size);
                    // number of portions served is n * 3 - (number of people with at most 2 portions) - (number of people with at most 1 portion)
                    int portion_cnt = n * 3 - ps[p2] - ps[p1];
                    best = Math.min(best, a * (portion_cnt * i * 6 / d - total * 6) + b * portion_cnt * 6);
                }
            }
            if (best % 6 == 0)
                System.out.println(best / 6);
            else if (best % 2 == 0)
                System.out.println(best / 2 + " / 3");
            else if (best % 3 == 0)
                System.out.println(best / 3 + " / 2");
            else
                System.err.println("Something wrong here!");
        }
    }
}