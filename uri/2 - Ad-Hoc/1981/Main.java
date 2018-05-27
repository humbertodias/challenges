import java.util.*;
import java.math.*;

class f
{
  BigInteger fib(BigInteger n)
  {
  if ((n.equals("1"))||(n.equals("0"))) return n;
  else return fib(n.subtract("1")) + fib(n.subtract("2"));
  }
}
 
 
 
class Main
{
  public static void main(String[] args)
  {
  int n;
  Scanner sc=new Scanner(System.in);
  String str;
  n=Integer.parseInt(sc.nextLine());
  BigInteger k,p,q;
  while(n>0)
  {
    n=n-1;
    str=sc.nextLine();
    StringTokenizer st=new StringTokenizer(str);
    while(st.hasMoreTokens())
    {
    k=Integer.parseInt(st.nextToken());
    p=Integer.parseInt(st.nextToken());
    q=Integer.parseInt(st.nextToken());
    }
    f f1=new f();
    BigInteger x,y,z;
    x=(f1.fib(k)*f1.fib(k+1));
    z=p.pow(q);
    z=(2*z*(f1.fib(k+2)-1));
    y=p.pow(2*q);
    y=(k*(y));
    y=y.mod(100000007);
    x=x.mod(100000007);
    z=z.mod(100000007);
    x=x.add(y);
    x=x.add(z);
    x=x.mod(100000007);
    System.out.println(x);
    }
  }
}
