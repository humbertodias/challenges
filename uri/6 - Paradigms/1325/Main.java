import java.io.*;
import java.util.*;

public class Main 
{

    public String replace( String s, char a, char b, char c, char d )
    {
        int i;
        char arr[] = s.toCharArray();
        String result;

        int p = -1;
        for( i=0; i<arr.length; i++ )
        {
            if( arr[i]==a || arr[i]==b )
            {
                p=i;
            }
        }

        if( p==-1 )
        {
            result = "<none>";
        }
        else
        {
            if( arr[p]==a ) arr[p]=c; 
            else if( arr[p]==b ) arr[p]=d;
            for( i=p+1; i<arr.length; i++ )
            {
                if( arr[i]==c ) arr[i] = a;
                else if( arr[i]==d ) arr[i] = b;
            }

            result = new String( arr );
        }

        return result;
    }

    public void doit() throws Exception
    {
        int i, j, k;

        Scanner sc = new Scanner( System.in );
        PrintStream ps = System.out;

        int nCases = sc.nextInt();
        while( nCases-->0 )
        {
            String map = sc.next();

            String up = replace( map, 's', 'r', 'p', 'q' );
            String dn = replace( map, 'p', 'q', 's', 'r' );
            String lf = replace( map, 'q', 'r', 'p', 's' );
            String rt = replace( map, 'p', 's', 'q', 'r' );

            ps.println( up + " " + dn + " " + lf + " " + rt );
        }
    }
   
    public static void main( String args[] ) throws Exception
    {
        new Main().doit();
    }
}