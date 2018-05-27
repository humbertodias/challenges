import java.util.*;
import java.io.*;
class Main{
    public static void main(String []args) throws Exception
    {
        int i, k, sum,n, TC=0;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String line;
        while( (line = in.readLine()) != null)
        {
            n = Integer.parseInt(line);
            TC++;
            sum=0;
            if(n==0)
            {
                sum++;
                out.printf("Caso %d: %d numero\n", TC,sum);
                out.printf("0\n");
            }
            else
            {
                for(i=0; i<=n; i++)
                {
                    for(k=1; k<=i; k++)
                    {
                        sum++;
                    }
                }
                out.printf("Caso %d: %d numeros\n", TC, sum+1);
                out.printf("0 ");
                for(i=0; i<=n; i++)
                {
                    for(k=1; k<=i; k++)
                    {
                        out.printf("%d", i);
                        if(k<n) out.printf(" ");
                    }
                }
                out.printf("\n");
            }
            out.printf("\n");
            out.flush();
        }
    }
}