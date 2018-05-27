import java.io.*;
import java.util.*;

public class Main 
{
    public int s, b;
    public int slots[], balls[];
    public int memo[][][];

    public int best( int start, int end, int ball, boolean first )
    {
        int result;
        int i;

        if( ball==b )
        {
            result = 0;
        }
        else 
        {
            if( memo[start%s][end%s][ball]==Integer.MAX_VALUE )
            {
                if( first )
                {
                    int bestsofar = -2000000;
                    for( i=0; i<s; i++ )
                    {
                        int profit = (-(slots[i]+slots[i+1])*balls[ball]) + best( i+2, i+s-1, ball+1, false );
                        if( profit>bestsofar )
                        {
                            bestsofar = profit;
                        }
                    }
                    memo[start%s][end%s][ball] = bestsofar;
                }
                else
                {
                    int bestsofar = -2000000;
                    for( i=start; i<end-2*(b-ball-1); ++i )
                    {
                        int profit = (-(slots[i]+slots[i+1])*balls[ball]) + best( i+2, end, ball+1, false );
                        if( profit>bestsofar )
                        {
                            bestsofar = profit;
                        }
                    }
                    memo[start%s][end%s][ball] = bestsofar;
                }
            }
            result = memo[start%s][end%s][ball];
        }

        return result;
    }

    public void doit() throws Exception
    {
        int i, j, k;

        int count = 0;

        Scanner sc = new Scanner( System.in );
        PrintStream ps = System.out;

        for(;;)
        {
            s = sc.nextInt();
            b = sc.nextInt();

            if( s==0 && b==0 ) break;

            slots = new int[s+s];
            for( i=0; i<s; i++ )
            {
                slots[i] = sc.nextInt();
                slots[s+i] = slots[i];
            }

            balls = new int[b];
            for( i=0; i<b; i++ )
            {
                balls[i] = sc.nextInt();
            }

            memo = new int[s][s][b];
            for( i=0; i<s; i++ )for( j=0; j<s; j++ )
            {
                Arrays.fill( memo[i][j], Integer.MAX_VALUE );
            }

            ps.println( best( 0, 0, 0, true ) );
        }
    }
   
    public static void main( String args[] ) throws Exception
    {
        new Main().doit();
    }
}