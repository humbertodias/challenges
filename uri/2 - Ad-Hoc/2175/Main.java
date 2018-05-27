import java.util.*;

public class Main{

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        double O,B,I;

        while(scanner.hasNext()){
            O = scanner.nextDouble();
            B = scanner.nextDouble();
            I = scanner.nextDouble();

            //Otavio, Bruno e Ian

            if(O < B && O < I)
                System.out.println("Otavio");
            else if(B < O && B < I)
                System.out.println("Bruno");
            else if(I < B && I < O)
                System.out.println("Ian");
            else
                System.out.println("Empate");

        }
    }

}