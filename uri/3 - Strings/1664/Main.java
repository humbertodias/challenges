import java.io.*;
import java.util.*;
 
class Main
{
	public static void main( String args[] ) throws IOException
	{
		BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
		HashSet<String> set = new HashSet<String>();
 
		String[] line;
		int num = 0, denum = 0, div;
 
		while( in.ready() )
		{
			line = in.readLine().split( "[^a-zA-Z]+" );
 
			//System.out.println( Arrays.toString( line ) );
 
			for( int i = 0; i < line.length; ++i )
			{
				if( line[i].equals( "BULLSHIT" ) )
				{
					++denum;
					num += set.size();
					set.clear();
				}
 
				else if( line[i].length() != 0 )
				{
					set.add( line[i].toLowerCase() );
				}
			}
		}
		div = gcd( num, denum );
 
		System.out.printf( "%d / %d\n", num / div, denum / div );
	}
 
	public static int gcd( int a, int b )
	{
		while( b != 0 )
		{
			int t = b;
			b = a % b;
			a = t;
		}
 
		return a;
	}
}
