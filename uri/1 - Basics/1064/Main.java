import java.util.*;
class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        double post = 0.0;
        double soma = 0.0;
        double a = scanner.nextDouble();
        if(a >= 0.0){
             post += 1.0;
             soma += a;
        }
        double b = scanner.nextDouble();
        if(b >= 0.0){
             post += 1.0;
             soma += b;
        }
        double c = scanner.nextDouble();
        if(c >= 0.0){
             post += 1.0;
             soma += c;
        }
        double d = scanner.nextDouble();
        if(d >= 0.0){
             post += 1.0;
             soma += d;
        }
        double e = scanner.nextDouble();
        if(e >= 0.0){
             post += 1.0;
             soma += e;
        }
        double f = scanner.nextDouble();
        if(f >= 0.0){
             post += 1.0;
             soma += f;
        }
        
        System.out.printf("%.0f valores positivos\n", post);
        System.out.printf("%.1f\n", soma/post);
    }
}