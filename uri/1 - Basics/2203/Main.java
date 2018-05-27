import java.util.*;
class Main{
    public static void main(String []args)
    {
        double x1, y1, x2, y2, v, r1, r2, X, Y, dstnce, range;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){
            x1 = scanner.nextDouble();
            y1 = scanner.nextDouble();
            x2 = scanner.nextDouble();
            y2 = scanner.nextDouble();
            
            v = scanner.nextDouble(); 
            r1 = scanner.nextDouble(); 
            r2 = scanner.nextDouble(); 
            
            X = (x2-x1)*(x2-x1);
            Y = (y2-y1)*(y2-y1);
            dstnce = Math.sqrt(X+Y);
            dstnce += v*1.50;
            range = r1+r2;
            if(dstnce > range) System.out.printf("N\n");
            else System.out.printf("Y\n");
        }
    }
}