/* 
*  Solution: geometry, intervals
*  Complexity: O(n^2)
*/

import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class circle implements Comparable<circle> {
  int x, y, r;
  circle(int x_, int y_, int r_) {
    x = x_;
    y = y_;
    r = r_;
  }
  public double d2orig() {
    return Math.sqrt(x*x + y*y);
  }
  public double dist() {
    return d2orig() - r;
  }
  public int compareTo(circle c) {
    return x*x + y*y - r*r - (c.x*c.x + c.y*c.y - c.r*c.r);
  }
}

public class Main {
  final static double eps = 1e-9;
  double adjust(double d) {
    d = Math.IEEEremainder(d, Math.PI * 2);
    if (d < 0)
      d += Math.PI * 2;
    return d;
  }
  // determine if the interval [from, to] is covered by an interval in
  // blocked_from, blocked_to or not
  boolean is_visible(ArrayList<Double> blocked_from, ArrayList<Double> blocked_to, double from, double to) {
    int j = 0, l = blocked_to.size();
    while(j < l && blocked_to.get(j)+eps < from)
      ++j;
    // now j >= l or blocked_to[j] >= from
    // check if view is blocked completely
    if (j < l && blocked_from.get(j) <= from+eps && blocked_to.get(j) >= to-eps)
      return false;
    // update blocked intervals
    int s = j;
    while(j < l && blocked_from.get(j)-eps <= to) {
      from = Math.min(from, blocked_from.get(j));
      to = Math.max(to, blocked_to.get(j));
      ++j;
    }
    l = j - s;
    while(l-- > 0) {
      blocked_from.remove(s);
      blocked_to.remove(s);
    }
    blocked_from.add(s, from);
    blocked_to.add(s, to);
    return true;
  }
  Main() throws Exception {
    Scanner in = new Scanner(System.in);
    DecimalFormat df = new DecimalFormat("0.000", new DecimalFormatSymbols(Locale.US));
    while(true) {
      int n = in.nextInt();
      if (n == 0)
        break;
      circle [] c = new circle[n];
      for (int i=0; i<n; ++i) {
        int x = in.nextInt();
        int y = in.nextInt();
        int r = in.nextInt();
        c[i] = new circle(x, y, r);
      }
      Arrays.sort(c);
      ArrayList<Double> blocked_from = new ArrayList<Double>();
      ArrayList<Double> blocked_to = new ArrayList<Double>();
      double best = 0;
      for (int i=0; i<n; ++i) {
        double dist = c[i].d2orig();
        double phi = Math.atan2(c[i].y, c[i].x);
        double phi2 = Math.asin(c[i].r / dist);
        double from = adjust(phi - phi2);
        double to = adjust(phi + phi2);
        if (to < from) {
          // in this case, split the interval in two parts
          // and check them individually
          boolean visible = is_visible(blocked_from, blocked_to, from, Math.PI * 2);
          // call is_visible again (is necessary, even if visible is
          // already set to true (function modifies blocked_from, blocked_to)
          if (is_visible(blocked_from, blocked_to, 0, to))
            visible = true;
          if (visible)
            best = Math.max(best, c[i].dist());
        }
        else if (is_visible(blocked_from, blocked_to, from, to))
          best = Math.max(best, c[i].dist());
      }
      System.out.println(df.format(best));
    }
  }
  public static void main(String [] args) throws Exception {
    new Main();
  }
}