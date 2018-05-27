import java.util.*;
class Main{

  public static void main(String []args)
  {
    int L = 0 , C = 0, R1 = 0, R2 = 0;
    Scanner scanner = new Scanner(System.in);
    while(scanner.hasNext())
    {
      
      L = scanner.nextInt();
      C = scanner.nextInt();
      R1 = scanner.nextInt();
      R2 = scanner.nextInt();

      if(L == 0 && C == 0 && R1 == 0 && R2 == 0) break;

      if(R1 * 2 <= L && R1 * 2 <= C && R2 * 2 <= L && R2 * 2 <= C)
      {
        if(Math.sqrt(Math.pow((R1 - (C - R2)), 2) + Math.pow(((L - R1) - R2), 2)) >= (R1 + R2))
          System.out.printf("S\n");
        else
          System.out.printf("N\n");
      }
      else
        System.out.printf("N\n");
    }

  }

}