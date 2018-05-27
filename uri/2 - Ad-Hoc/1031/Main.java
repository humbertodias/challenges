import java.util.*;
class Main{
  static int remaining(int n, int k) {
      int r = 0, i;
      for (i = 1; i < n; i++)
          r = (r + k) % i;

      return r;
  }

  public static void main(String []args){
      int n, x, y, j, num, pulo;
      Scanner scanner = new Scanner(System.in);
      while(true){
        n = scanner.nextInt();
        if(n == 0) break;
        y = 1;
        for(;;){
           if(remaining(n,y) != 11) y++;
           else break;
        }
        System.out.printf("%d\n",y);
      }
  }
  
}