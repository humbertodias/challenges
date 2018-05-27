import java.util.*;
class Main{
    public static void main(String []args){
        float s=0, n=0;
        Scanner scanner = new Scanner(System.in);
        char o = scanner.next().charAt(0);
        int x = 12;
        for (int i = 0; i <= 11; i++){
            x--;
            for (int j = 0; j <= 11; j++){
                
                if(scanner.hasNextFloat())
                    n = scanner.nextFloat();

                if (j < x)
                    s += n;
            }
        }
        if (o == 'S')
            System.out.printf("%.1f\n", s);
        else
            System.out.printf("%.1f\n", s / 66);
    }

}