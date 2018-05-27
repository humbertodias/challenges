import java.io.*;
import java.util.*;

public class Main {
  public static void main(String [] args) throws Exception {
    Scanner in = new Scanner(System.in);
    int tc = 1;
    while(true) {
      int r = in.nextInt();
      if (r == 0)
        break;
      int w = in.nextInt();
      int l = in.nextInt();
      System.out.println("Pizza " + tc++ + (w*w+l*l > 4*r*r? " does not fit" : " fits") + " on the table.");
    }
  }
}