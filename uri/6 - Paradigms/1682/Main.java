// Problem   Genetic Code
// Algorithm Backtracking
// Runtime   O(3^n)

import java.io.*;
import java.math.*;

public class Main
{
  static char[] s = new char[8192];
  static int end=0;
  static final int target=5000;

  static boolean strequal(int a, int b, int n)
  {
    for ( ; n>0 ; a++, b++, n--)
      if (s[a] != s[b])
        return false;
    return true;
  }

  static boolean isThue()
  {
    for (int len=1 ; end-len-len>=0 ; len++)
      if (strequal(end-len-len, end-len, len))
        return false;
    return true;
  }

  static boolean backtrack()
  {
    if (end == target)
      return true;
    ++end;
    for (s[end-1]='N' ; s[end-1]<='P' ; s[end-1]++)
      if (isThue() && backtrack())
        return true;
    --end;
    return false;
  }

  public static void main(String[] arg) throws Exception
  {
    backtrack();
    BufferedReader r = new BufferedReader( new InputStreamReader(System.in) );
    for (String line = r.readLine() ; line != null ; line = r.readLine())
    {
      int n = (new BigInteger(line)).intValue();
      if (n == 0) break;
      System.out.println(new String(s, 0, n));
    }
  }
}