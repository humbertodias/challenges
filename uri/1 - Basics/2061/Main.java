import java.util.*;

class Main{

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int n, m, i, j;
        int cc = 0, cf = 0;
        char a[] = new char[10];
        char c[] = "clicou\0".toCharArray();
        char f[] = "fechou\0".toCharArray();
     
        n = scanner.nextInt();
        m = scanner.nextInt();
        
        for(i=1; i<=m; i++) {
            a = scanner.next().toCharArray();
            for(j=0;j<=5;j++)
            {
                if(a[j] == c[j])
                    cc++;
                if(a[j] == f[j])
                    cf++;
            }
            if(cc == 6)
                n--;
     
            if(cf == 6)
                n++;
     
            cc = 0;
            cf = 0;
        }
     
        System.out.format("%d\n",n);
     
    }
}