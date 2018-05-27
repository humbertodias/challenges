import java.io.*;
import java.util.*;

public class Main 
{
    public void doit() throws Exception
    {
        int i, j, k;

        Scanner sc = new Scanner( System.in );
        PrintStream ps = System.out;

        for(;;)
        {
            int n = sc.nextInt();
            int c = sc.nextInt();
            k = sc.nextInt();

            if( n==0 && c==0 && k==0 ) break;

            int counts[] = new int[k+1];
            Arrays.fill( counts, 0 );

            for( i=0; i<n; i++ ) for( j=0; j<c; j++ )
            {
                ++counts[sc.nextInt()];
            }

            int min = Integer.MAX_VALUE;
            for( i=1; i<=k; i++ )
            {
                if( counts[i]<min )
                {
                    min = counts[i];
                }
            }

            boolean first = true;
            for( i=1; i<=k; i++ ) if( counts[i]==min )
            {
                if( first )
                {
                    first = false;
                }
                else
                {
                    ps.print( " " );
                }
                ps.print( i );
            }
            ps.println();
        }
    }
   
    public static void main( String args[] ) throws Exception
    {
        new Main().doit();
    }
}