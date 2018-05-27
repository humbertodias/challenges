import java.util.*;
class Main{
    
    public static void main(String []args)
    {
        int tst, Dab, Gab, a1, a2, d1, d2, l1, l2, bns;
        Scanner scanner = new Scanner(System.in);
        tst = scanner.nextInt();
        while(tst-- > 0)
        {
            bns = scanner.nextInt();
            a1 = scanner.nextInt();
            d1 = scanner.nextInt();
            l1 = scanner.nextInt();
            a2 = scanner.nextInt();
            d2 = scanner.nextInt();
            l2 = scanner.nextInt();
            
            Dab = (a1+d1)/2;
            if(l1%2==0) Dab += bns;
            Gab = (a2+d2)/2;
            if(l2%2==0) Gab += bns;
            if(Dab == Gab) System.out.printf("Empate\n");
            else System.out.printf((Dab > Gab)? "Dabriel\n" : "Guarte\n");
        }

    }

}