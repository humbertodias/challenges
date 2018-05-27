import java.util.*;
import java.io.*;

public class Main {
    public static void main(String... args) throws Exception {
        BufferedReader in = new BufferedReader( new InputStreamReader(System.in) );
        String line;
        while ((line = in.readLine()) != null) {
            Scanner s = new Scanner(line);

            int n = s.nextInt();
            long m = s.nextLong();

            if (n == 0) {
                break;
            }
            int p[] = new int[n + 1];
            s = new Scanner(in.readLine());
            for (int i = 1; i <= n; i++) {
                p[i] = s.nextInt();
            }

            line = in.readLine();
            int set[] = new int[n + 1];
            int len[] = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                if (set[p[i]] == 0) {
                    int steps = 0;
                    for (int j = p[i]; set[j] == 0; j = p[j]) {
                        set[j] = i;
                        steps++;
                    }
                    len[i] = steps;
                }
            }
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < n; i++) {
                int l = len[set[i + 1]];
                long k = (l - (m % l));
                int target = i + 1;
                while (k-- > 0) {
                    target = p[target];
                }
                b.append(line.charAt(target - 1));
            }
            System.out.println(b.toString());
        }
        in.close();
    }
}
