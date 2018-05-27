import java.io.*;
import java.util.*;
public class Main
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);
        int m = sc.nextInt();
        int n = sc.nextInt();
        HashMap<String, Double> hash = new HashMap<String, Double>();
        for (int i=0; i<m; i++)
        {
            String party = sc.next();
            double p = sc.nextDouble();
            hash.put(party, p);
        }
        for (int i=0; i<n; i++)
        {
            double sum = 0.0;
            while (true)
            {
                String token = sc.next();
                if (token.equals("+"))
                    continue;
                if (token.matches("[<>=]+"))
                {
                    int k = sc.nextInt();
                    k *= 10;
                    sum = Math.round(sum * 10.0);
                    Boolean res =
                        token.startsWith("<") && sum < k ||
                        token.startsWith(">") && sum > k ||
                        token.endsWith("=") && sum == k;
                    System.out.println("Guess #" + (i+1) + " was " + (res ? "" : "in") + "correct.");
                    break;
                }
                else
                    sum += hash.get(token);
            }
        }
    }
}