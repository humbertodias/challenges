import java.util.*;
class Main{
    public static void main(String []args)
    {
        String a,b;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 1; i <= n; ++i)
        {
            a = scanner.next();
            b = scanner.next();
            if(a.equals(b)) System.out.printf("Caso #%d: De novo!\n", i);
            else if(a.equals("tesoura") && b.equals("papel")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("papel") && b.equals("pedra")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("pedra") && b.equals("lagarto")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("lagarto") && b.equals("Spock")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("Spock") && b.equals("tesoura")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("tesoura") && b.equals("lagarto")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("lagarto") && b.equals("papel")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("papel") && b.equals("Spock")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("Spock") && b.equals("pedra")) System.out.printf("Caso #%d: Bazinga!\n", i);
            else if(a.equals("pedra") && b.equals("tesoura") ) System.out.printf("Caso #%d: Bazinga!\n", i);
            else System.out.printf("Caso #%d: Raj trapaceou!\n", i);
        }
    }

}