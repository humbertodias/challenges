import java.io.*;
import java.util.*;

public class Main 
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "frog";
    }

    public class Move implements Comparable
    {
        public int r, c, cost;

        public Move( int rr, int cc, int cst )
        {
            r=rr; c=cc; cost=cst;
        }

        public String toString()
        {
            return "{Move:r=" + r + ", c=" + c + ", cost=" + cost + "}";
        }

        public int compareTo( Object o )
        {
            Move m = (Move)o;
            int diff = cost - m.cost;
            if( diff==0 ) diff = hashCode() - m.hashCode();
            return diff;
        }
    };

    public void doit() throws Exception
    {
        int i, j, k;

        sc = new Scanner( System.in );
        ps = System.out;

        int costs[][] =
        {
            { 7, 6, 5, 6, 7 },
            { 6, 3, 2, 3, 6 },
            { 5, 2, 9, 2, 5 },
            { 6, 3, 2, 3, 6 },
            { 7, 6, 5, 6, 7 }
        };

        for(;;)
        {
            int c = sc.nextInt();
            int r = sc.nextInt();
            if( c==0 && r==0 ) break;

            int cf = sc.nextInt()-1;
            int rf = sc.nextInt()-1;
            int ct = sc.nextInt()-1;
            int rt = sc.nextInt()-1;

            boolean dry[][] = new boolean[r][c];
            for( i=0; i<r; i++ )
            {
                Arrays.fill( dry[i], true );
            }

            int w = sc.nextInt();
            for( k=0; k<w; k++ )
            {
                int c1 = sc.nextInt()-1;
                int r1 = sc.nextInt()-1;
                int c2 = sc.nextInt()-1;
                int r2 = sc.nextInt()-1;
                for( i=r1; i<=r2; i++ )for( j=c1; j<=c2; j++ )
                {
                    dry[i][j] = false;
                }
            }

            PriorityQueue<Move> q = new PriorityQueue<Move>();
            q.add( new Move( rf, cf, 0 ) );
            int best = Integer.MAX_VALUE;
            while( q.size()>0 )
            {
                Move m = q.poll();
                if( m.r==rt && m.c==ct )
                {
                    best = m.cost;
                    break;
                }
                
                if( dry[m.r][m.c] )
                {
                    dry[m.r][m.c] = false;

                    for( int di=-2; di<=2; di++ )for( int dj=-2; dj<=2; dj++ ) if( di!=0 || dj!=0 )
                    {
                        i = m.r+di;
                        j = m.c+dj;
                        if( i>=0 && i<r && j>=0 && j<c && dry[i][j] )
                        {
                            q.add( new Move( i, j, m.cost+costs[di+2][dj+2] ) );
                        }
                    }
                }
            }

            if( best==Integer.MAX_VALUE )
            {
                ps.println( "impossible" );
            }
            else
            {
                ps.println( best );
            }

        }
    }
   
    public static void main( String args[] ) throws Exception
    {
        new Main().doit();
    }
}
