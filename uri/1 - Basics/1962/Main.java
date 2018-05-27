import java.util.*;
class Main{
    public static void main(String []args)
    {
        double t, year;
        double diff;
        Scanner scanner = new Scanner(System.in);
        double n = scanner.nextDouble();
        for(double i=0; i< n; i++){

            t = scanner.nextDouble();

            diff = 2015 - t;
            if (diff <= 0)
                year = diff * -1 + 1;
            else
                year = diff;

            System.out.printf("%.0f %s\n", year, (diff <= 0 ? "A.C." : "D.C."));

        }
    }
}