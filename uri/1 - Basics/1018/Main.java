import java.util.*;

class Main{
    public static void main(String [] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        int inteiro = scanner.nextInt();    
        System.out.println(inteiro);    
        int[] banknotes = {100, 50, 20, 10, 5, 2, 1};
        int aux = inteiro ;
        for(int div: banknotes){
            System.out.format("%d nota(s) de R$ %d,00\n", aux/div, div );
            aux = aux % div;
        }
    }
}