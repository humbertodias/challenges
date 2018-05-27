import java.util.*;
class Main{
    public static void main(String []args)
    {
        Scanner scanner = new Scanner(System.in);
        int a,b,c=0,d,e,f,g,h,i,j,l=0,m=0,x=0,n,p;
        int par[] = new int[5];
        int impar[] = new int[5];
        int ara[] = new int[15];
        for(b=0; b<15; b++)
            ara[b] = scanner.nextInt();
        for(a=0; a<15; a++)
        {
            if(l==5)
            {
                for(n=0; n<5; n++)
                    System.out.printf("impar[%d] = %d\n", n, impar[n]);
                l=0;
            }
            if(m==5)
            {
                for(p=0; p<5; p++)
                    System.out.printf("par[%d] = %d\n", p, par[p]);
                m=0;
            }

            if(ara[a]%2!=0)
            {
                impar[c]=ara[a];
                ++c;
                l++;
                if(c==5) c=0;
            }
            if(ara[a]%2==0)
            {
                par[x]=ara[a];
                ++x;
                m++;
                if(x==5) x=0;
            }
        }
        for(i=0; i<l; i++)
                System.out.printf("impar[%d] = %d\n", i, impar[i]);
        for(j=0; j<m; j++)
                System.out.printf("par[%d] = %d\n", j, par[j]);
    }
}