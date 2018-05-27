import java.util.*;
class Main{
    public static void main(String []args){
        int c, n, m, im = 0, i = 0;
        Scanner scanner = new Scanner(System.in);
        c = scanner.nextInt();
        n = scanner.nextInt();
        m = n;
        while(c-- > 0){
            i++;
            
            if(scanner.hasNextInt())
                n = scanner.nextInt();

            if (n < m){
                im = i;
                m = n;
            }
        }
        System.out.printf("Menor valor: %d\n", m);
        System.out.printf("Posicao: %d\n", im);
    }
}