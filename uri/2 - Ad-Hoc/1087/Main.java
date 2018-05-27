import java.util.*;
class Main{
  public static void main(String []args){
      int x1,y1,x2,y2;
      Scanner scanner = new Scanner(System.in);
      while(true){
        x1 = scanner.nextInt();
        y1 = scanner.nextInt();
        x2 = scanner.nextInt();
        y2 = scanner.nextInt();
         if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;
         
         if(x1 == x2 && y1 == y2) System.out.printf("0\n");
         else if((x2-x1) == -(y2-y1) || -(x2-x1) == -(y2-y1) || -(x2-x1) == (y2-y1) || (x2-x1) == (y2-y1)) System.out.printf("1\n");
         else if(x1 == x2 || y1 == y2) System.out.printf("1\n");
         else System.out.printf("2\n");
      }
  }
}