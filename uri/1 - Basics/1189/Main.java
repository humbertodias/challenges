import java.util.*;
class Main{
    public static void main(String []args){
        int i, j, l = 0;
        double s = 0, n = 0;
        Scanner scanner = new Scanner(System.in);
        char o = scanner.next().charAt(0);
        for (i = 0; i <= 11; i++){
            for (j = 0; j <= 11; j++){
                if(scanner.hasNextDouble())
                    n = scanner.nextDouble();
                if (j < l)
                    s += n;
            }
            if (i < 5)
                l++;
            else if (i >= 6)
                l--;
        }
        if (o == 'S')
            System.out.printf("%.1f\n", s);
        else
            System.out.printf("%.1f\n", s / 30);

    }
}