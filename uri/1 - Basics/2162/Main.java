import java.util.*;
class Main{
    public static void main(String []args)
    {
        int n, i, cndtn = 1;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int ara[] = new int[n];
        for(i=0; i<n; i++)
            ara[i] = scanner.nextInt();
        if(n==2 && ara[0]==ara[1]) cndtn = 0;
        else
        {
            for(i=2; i<n; i++)
            {
                if(ara[i] >= ara[i-1] && ara[i-1] >= ara[i-2])
                {
                    cndtn = 0;
                    break;
                }
                else if(ara[i] <= ara[i-1] && ara[i-1] <= ara[i-2])
                {
                    cndtn = 0;
                    break;
                }
            }
        }
        System.out.printf((cndtn==1)?"1\n":"0\n");
    }
}