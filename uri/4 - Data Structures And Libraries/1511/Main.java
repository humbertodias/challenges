import java.util.*;

public class Main{

  static int gcd(int a, int b)
  {
    if(a == 0 || b == 0) return a+b; // base case
    return gcd(b,a%b);
  }

  public static void main(String args[]){
    Scanner scanner = new Scanner(System.in);
    // int MAX = (int)Math.pow(10,5);
    int MAX = 500;
    int matrix[][] = new int[MAX][MAX];

    String[] parts;
    int q, x, y, d;
    while(scanner.hasNext()){
      q = scanner.nextInt();
      for(int i=0; i < q; i++){
        parts = scanner.nextLine().split(" ");
        if(parts.length != 4) continue;
        System.out.println(Arrays.toString(parts) ) ;        
        x = Integer.parseInt(parts[1]);
        y = Integer.parseInt(parts[2]);
        d = Integer.parseInt(parts[3]);

        System.out.format("%d %d %d\n", x, y, d);

        switch(parts[0]){
          case "QUERY":
          break;
          case "SET":
            matrix[x][ Math.abs(y) ]=d;
          break;
        }

      }
      if(!scanner.hasNextInt()) break;

    }

  }

}