import java.util.*;

// http://mathworld.wolfram.com/LookandSaySequence.html
// http://oeis.org/A006715
// http://en.literateprograms.org/Look_and_say_sequence_(Java)
class Main
{
    public static String[] look_and_say(String seed, int len)
    {
        String[] seq = new String[len];
        seq[0] = seed;

        for (int i = 1; i < len; i++) {
            String val = seq[i-1];

            StringBuilder nextval = new StringBuilder();
            for (int ix = 0; ix < val.length(); ) {
                char ch = val.charAt(ix);
                int n;
                for (n = 1; ++ix < val.length() && val.charAt(ix)==ch; n++)
                    ;
                nextval.append(n).append(ch);
            }
            seq[i] = nextval.toString();
        }

        return seq;
    }
    public static void main(String[] args)
    {
        int n;
        String seq[];
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){
          n = scanner.nextInt();
          seq = look_and_say("3", n);
          System.out.println(seq[n-1]);
        }
    }
}
