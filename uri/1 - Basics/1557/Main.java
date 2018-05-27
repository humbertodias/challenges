import java.util.*;

class Main{
    static int dg(int x)
    {
        int a=x,b=0;
        while(a != 0)
        {
            a/=10;
            b++;
        }
        return b;
    }
    public static void main(String []args)
    {
        int i=0,j=0,N,a,b,c=1,x,y=0,I,d,e=0,f,g,h;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext())
        {
            N = scanner.nextInt();
            if(N==0) break;
            else
            {
                int ara[][] = new int[N][N];
                I=N-1;
                for(x=0,c=1,y=0; x<N; x++)
                {
                    for(a=y,b=0; a>=0; a--,b++)
                        ara[a][b]=c;
                    y++; c*=2;
                }
                for(x=1,y=1; x<N; x++)
                {
                    for(a=I,b=y; b<=I; a--,b++)
                        ara[a][b]=c;
                    y++; c*=2;
                }
                d=dg(ara[I][I]);
                for(i=0; i<N; i++)
                {
                    for(j=0; j<N; j++)
                    {
                        if(j==0)
                        {
                            h=ara[i][j];
                            e=dg(h);
                            g=d-e;
                            for(f=1;f<=g; f++)
                                System.out.printf(" ");
                            System.out.printf("%d",ara[i][j]);
                        }
                        else
                        {
                            h=ara[i][j];
                            e=dg(h);
                            g=d-e;
                            for(f=1;f<=g; f++)
                                System.out.printf(" ");
                            System.out.printf(" %d",ara[i][j]);
                        }
                    }
                    System.out.printf("\n");
                }
                System.out.printf("\n");
            }
        }
    }

}