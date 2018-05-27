import java.util.*;
class Main{
    public static void main(String args[])  
    {  
        Scanner scanner = new Scanner(System.in);
        int tst = scanner.nextInt();  
        char f[], s[];  
        while( tst-- > 0)  
        {  
            f = scanner.next().toCharArray();
            s = scanner.next().toCharArray();
            if(f[1]=='e' && s[1]=='e') System.out.format("Sem ganhador\n");  
            else if(f[1]=='t' && s[1]=='t') System.out.format("Aniquilacao mutua\n");  
            else if(f[1]=='a' && s[1]=='a') System.out.format("Ambos venceram\n");  
            else if(f[1]=='t' || (f[1]=='e' && s[1]=='a'))  
                System.out.format("Jogador 1 venceu\n");  
            else System.out.format("Jogador 2 venceu\n");  
        }  

    } 
}