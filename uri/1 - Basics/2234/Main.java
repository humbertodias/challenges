import java.util.*;

class Main{

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        float h, p;
        while(scanner.hasNext()){
            h = scanner.nextFloat();
            p = scanner.nextFloat();
            System.out.printf("%.2f\n", h/p);
        }
    }
}