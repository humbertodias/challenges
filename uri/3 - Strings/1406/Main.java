import java.io.*;
import java.util.*;
import java.awt.*;

public class Main 
{
    public Scanner sc;
    public PrintStream ps;

    public class Word
    {
        public String w;
        public HashSet<String> bits;
        public int bitindices[];
        public boolean has[];

        public Word( String word )
        {
            w = word;
            bits = new HashSet<String>();
        }

        public String toString()
        {
            return "{Word:w=" + w + ", bits=" + bits + "}";
        }

        public void computeIndices()
        {
            int i=0, k;
            bitindices = new int[bits.size()];
            has = new boolean[uses.length];
            Arrays.fill( has, false );
            for( String bit : bits )
            {
                k = getIndex( bit );

                bitindices[i++] = k;
                has[k] = true;
            }
        }
    };

    public Word tunes[][];
    public Hashtable<String,LinkedList<Point>> bits;
    public int best;
    public boolean artistused[];
    public String artists[];
    public int uses[];
    public int len[];
    public String bitstrings[];
    public Hashtable<String,Integer> indices;
    public int nextIndex;

    public int getIndex( String s )
    {
        Integer index = indices.get( s );
        if( index==null )
        {
            index = nextIndex;
            indices.put( s, index );
            len[nextIndex++] = s.length();
        }

        return index;
    }

    public void breakintobits( int a, int b )
    {
        int i, j;
        String word = tunes[a][b].w;

        for( i=0; i<word.length(); i++ ) for( j=i+1; j<=word.length(); j++ )
        {
       
            String bit = word.substring( i, j );

            if( word.indexOf(bit)==i )
            {
                LinkedList<Point> words = bits.get( bit );
                if( words==null )
                {
                    words = new LinkedList<Point>();
                }

                words.add( new Point( a, b ) );
                bits.put( bit, words );

                tunes[a][b].bits.add( bit );
            }
        }
    }

    public void solve( int level )
    {
        int i;
        int n = tunes.length;

        if( level==0 )
        {
            int sum = 0;
            for( i=0; i<n; i++ )
            {
                int bitsize = 100000;

                for( int index : tunes[i][artistused[i]?1:0].bitindices )
                {
                    if( uses[index]==1 && len[index]<bitsize )
                    {
                        bitsize = len[index];
                    }
                }

                sum += bitsize;
            }
            if( sum<best ) best=sum;
        }
        else
        {
            --level;

            solve( level );

            for( i=0; i<n; i++ ) if( tunes[i][1].w.equals( artists[level] ) )
            {
                for( int index : tunes[i][1].bitindices )
                {
                    if( !tunes[i][0].has[index] )
                    {
                        ++uses[index];
                    }
                }

                artistused[i] = true;
                solve( level );
                artistused[i] = false;

                for( int index : tunes[i][1].bitindices )
                {
                    if( !tunes[i][0].has[index] )
                    {
                        --uses[index];
                    }
                }
            }
        }
    }

    public void doit() throws Exception
    {
        int i, j, k;

        sc = new Scanner( System.in );
        ps = System.out;

        for(;;)
        {
            int n = sc.nextInt();
            if( n==0 ) break;

            tunes = new Word[n][2];
            bits = new Hashtable<String,LinkedList<Point>>();
            HashSet<String> artistset = new HashSet<String>();

            // Read all the tunes and artists, break them into bits
            for( i=0; i<n; i++ )
            {
                String tune = sc.next();
                tunes[i][0] = new Word( tune );
                breakintobits( i, 0 );

                String artist = sc.next();
                tunes[i][1] = new Word( artist );
                breakintobits( i, 1 );
                artistset.add( artist );
            }

            // If any bit appears in more than one song title, it's unusable
            // as a unique identifier. So, remove it.

            Iterator<String> it = bits.keySet().iterator();
            while( it.hasNext() )
            {
                String bit = it.next();
                LinkedList<Point> words = bits.get(bit);

                int count = 0;
                for( Point p : words )
                {
                    if( p.y==0 ) ++count;
                    if( count>1 ) break;
                }

                if( count>1 )
                {
                    for( Point p : words )
                    {
                        tunes[p.x][p.y].bits.remove( bit );
                    }
                    it.remove();
                }
            }

            // To speed things up, we'll use a lot of arrays.
            //bitstrings = (String[])bits.keySet().toArray( new String[0] );
            uses = new int[bits.keySet().size()];
            len = new int[bits.keySet().size()];
            Arrays.fill( uses, 0 );

            indices = new Hashtable<String, Integer>();
            nextIndex = 0;
            for( i=0; i<n; i++ )
            {
                tunes[i][0].computeIndices();
                tunes[i][1].computeIndices();

                for( int index : tunes[i][0].bitindices )
                {
                    ++uses[index];
                }
            }

            // Recursively look for a solution
            best = Integer.MAX_VALUE;
            artists = (String[])artistset.toArray( new String[0] );
            artistused = new boolean[n];

            solve( artists.length );

            ps.println( best );
        }
    }
   
    public static void main( String args[] ) throws Exception
    {
        new Main().doit();
    }
}