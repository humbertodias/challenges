import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();
    String rev = new StringBuilder(s).reverse().toString();
    System.out.println(rev);
  }
}