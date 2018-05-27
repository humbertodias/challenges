import java.util.*;
class Main{
    public static void main(String []args){
        int i, j, x = 11;
        float s = 0, n = 0;
        Scanner scanner = new Scanner(System.in);
        char o = scanner.next().charAt(0);
        for (i = 0; i <= 11; i++){
            for (j = 0; j <= 11; j++){
                if(scanner.hasNextFloat())
                    n = scanner.nextFloat();
                if (x < j)
                    s += n;
            }
            x--;
        }
        if (o == 'S')
            System.out.printf("%.1f\n", s);
        else
            System.out.printf("%.1f\n", s / 66);
    }
}