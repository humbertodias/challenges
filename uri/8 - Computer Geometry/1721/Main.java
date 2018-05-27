import java.util.*;

class Main{

  static char name[][] = new char[1000][64];
  static int mn;
  static int fcity(char [] n)
  {
    int i;
    for(i=0; i<mn; i++)
      {
        if (String.valueOf(name[i]).equals(String.valueOf(n)) ) return i;
      }
    return -1;
  }

  public static void main(String []args)
  {

  double ER=6378.0;

  char c1[] = new char[64];
  char c2[] = new char[64];
  char c3[] = new char[64];
  int i1, i2, i3;
  double x[] = new double[1999];
  double y[] = new double[1000];
  double x3, x2, y3, y2, z3, z2, res;

  double M_PI = 3.14159265358979323846;

    Scanner scanner = new Scanner(System.in);
    mn = 0;
    while(true)
      {
        name[mn] = scanner.next().toCharArray();
        if (name[mn][0] == '#') break;
        y[mn]=scanner.nextDouble();
        x[mn]=scanner.nextDouble();

        y[mn] = y[mn] * M_PI / 180.0;
        x[mn] = x[mn] * M_PI / 180.0;
        mn++;
      }
    while(true)
      {
        c1 = scanner.next().toCharArray();
        if (c1[0] == '#') break;
        c2 = scanner.next().toCharArray();
        c3 = scanner.next().toCharArray();
        i1 = fcity(c1); i2 = fcity(c2); i3 = fcity(c3);
        if ((i1==-1) || (i2==-1) || (i3==-1))
      {
        System.out.printf("%s is ? km off %s/%s equidistance.\n", String.valueOf(c3), String.valueOf(c1), String.valueOf(c2) );
      }
        else
      {
        x3 = (Math.cos(y[i1])*Math.sin(x[i1])) - (Math.cos(y[i2])*Math.sin(x[i2]));
        y3 = (Math.cos(y[i1])*Math.cos(x[i1])) - (Math.cos(y[i2])*Math.cos(x[i2]));
        z3 = (Math.sin(y[i1])) - (Math.sin(y[i2]));
        x2 = (Math.cos(y[i3])*Math.sin(x[i3]));
        y2 = (Math.cos(y[i3])*Math.cos(x[i3]));
        z2 = (Math.sin(y[i3]));
        res = (x3*x2 + y3*y2 + z3*z2) / (Math.sqrt(x3*x3+y3*y3+z3*z3));
        if (res<0) res=-res;
        res = (M_PI / 2 - Math.acos(res)) * ER;
        if ((y[i1]==y[i2]) && (x[i1]==x[i2])) res = 0.0;
        System.out.printf("%s is %d km off %s/%s equidistance.\n", String.valueOf(c3), (int) Math.floor(res+0.5), String.valueOf(c1), String.valueOf(c2) );
      }
      }
  }

}