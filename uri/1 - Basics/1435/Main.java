import java.util.*;
import java.io.*;
class Main{
    public static void main(String []args) throws Exception{
        int n, i, j, k, m, p, q, nl, np;
        // Scanner scanner = new Scanner(System.in);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out), true);

        String line;
        while ( (line = in.readLine()) != null ){
            // n = scanner.nextInt();
            n = Integer.parseInt(line);
            if (n == 0) break;

            k = n % 2;
            m = n / 2;

            nl = 1;
            q = n;

            for (i = 1; i <= n; i++){
                np = 1;
                p = 0;

                for (j = 0; j < n; j++){

                    if (j ==  0) System.out.printf(" ");
                    else out.printf("  ");

                    if (p == 0 && np != nl){
                        if (np < 10) out.printf(" ");
                        out.printf("%d",np);
                        np++;
                    } else if (np == nl && p < q){
                        if (nl < 10) out.printf(" ");
                        out.printf("%d",nl);
                        p++;
                    } else {
                        np--;
                        if (np < 10) out.printf(" ");
                        out.printf("%d",np);
                    }
                }

                if (i < m){
                    nl++;
                    q -= 2;
                } else if (i == m && k == 1){
                    nl++;
                    q = 1;
                } else if (i == m && k == 0){
                    q = 2;
                } else {
                    q += 2;
                    nl--;
                }

                out.printf("\n");
            }

            out.printf("\n");
        }
    }
}