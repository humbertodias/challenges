import java.util.*;
class Main{
    public static void main(String []args)
    {
        double n, ans = 0.0;
        n = new Scanner(System.in).nextDouble();
        while(n-- > 0)
        {
            ans+=2.0;
            ans = 1.0/ans;
        }
        ans += 1.0;
        System.out.printf("%.10f\n", ans);
    }
}
