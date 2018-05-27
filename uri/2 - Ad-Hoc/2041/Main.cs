using System;
using System.Text;

// http://mathworld.wolfram.com/LookandSaySequence.html
// http://oeis.org/A006715
// http://en.literateprograms.org/Look_and_say_sequence_(Java)
class URI
{
    public static string[] look_and_say(string seed, int len)
    {
        string[] seq = new string[len];
        seq[0] = seed;

        for (int i = 1; i < len; i++) {
            string val = seq[i-1];

            StringBuilder nextval = new StringBuilder();
            for (int ix = 0; ix < val.Length; ) {
                char ch = val[ix];
                int n;
                for (n = 1; ++ix < val.Length && val[ix]==ch; n++)
                    ;
                nextval.Append(n).Append(ch);
            }
            seq[i] = nextval.ToString();
        }

        return seq;
    }
    public static void Main(string[] args)
    {
     string [] seq;
     string s;
     int n;
     do {
          s = Console.ReadLine();
          if(s==null) break;
          n = int.Parse(s);
          seq = look_and_say("3", n);
          Console.WriteLine(seq[n-1]);
      } while (true);

    }
}
