import java.util.*;

class Main{

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int tst, i, n;
        while(scanner.hasNext())
        {
            tst = scanner.nextInt();
            for(i=1; i<=tst; i++)
            {
                n = scanner.nextInt();
                if(n%2!=0) System.out.format("%d\n", n*2-1);
                else System.out.format("%d\n", n*2-2);
            }
        }

    }

}