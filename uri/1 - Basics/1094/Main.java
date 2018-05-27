import java.util.*;

class Main{

    public static void main(String args[]){
        int q;
        char t;
        int total = 0;
        int coelho = 0;
        int sapo = 0;
        int rato = 0;
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        for(int i = 0; i < n; i++){
            q = scanner.nextInt();
            t = scanner.next().trim().charAt(0);;

            total += q;
            
            if(t == 'C') coelho += q;
            if(t == 'S') sapo += q;
            if(t == 'R') rato += q;
        }
        
        System.out.printf("Total: %d cobaias\n", total);
        System.out.printf("Total de coelhos: %d\n", coelho);
        System.out.printf("Total de ratos: %d\n", rato);
        System.out.printf("Total de sapos: %d\n", sapo);
        System.out.printf("Percentual de coelhos: %.2f %%\n", ((float)coelho/(float)total)*100.00f);
        System.out.printf("Percentual de ratos: %.2f %%\n", ((float)rato/(float)total)*100.00f);
        System.out.printf("Percentual de sapos: %.2f %%\n", ((float)sapo/(float)total)*100.00f);
        
    }

}