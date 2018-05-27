import java.util.*;
class Main{
    public static void main(String []args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int q=a/b;
        int r=a%b;
        if(a < 0 && b < 0)
        {
            if(r<0 && q<=0)
            {
                q++;
                r=-(b*q)+a;
            }
            else if(r<0 && q>0)
            {
                q++;
                r=-(b*q)+a;
            }
        }
        else
        {
            if(r<0 && q<=0)
            {
                q--;
                r=-(b*q)+a;
            }
            else if(r<0 && q>0)
            {
                q++;
                r=-(b*q)+a;
            }
        }
        System.out.printf("%d %d\n", q, r);
    }
}