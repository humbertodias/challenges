import java.util.*;

public class Main{

  static int[] isMagicNumber(int n){
    int m = n/4;

    int p1 = m-4;
    int p2 = m-3;
    int p3 = m-2;
    int p4 = m-1;
    boolean isMN = (p1 + m) == (p2 - m) && (p3 * m) == (p4 / m);

//z = A / (m+1)^2
// z = (m - 3)

// z = A / (m+1)^2
// 128 / (32+1) ^2
// 128 / 1089
// z = 0.11753902662994

// 0.11753902662994 / 


    System.out.println(  isMN );
    return new int[]{p1,p2,p3,p4};
  }

  public static void main(String [] args){
    Scanner scanner = new Scanner(System.in);
    int N;
    while(scanner.hasNext()){

      N = scanner.nextInt();
      if(N==0) break;
      for(int x: isMagicNumber(N)){
        System.out.printf("%d ", x);
      }
      System.out.println();

    }
  }

}