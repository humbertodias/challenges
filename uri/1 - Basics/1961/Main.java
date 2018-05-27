import java.util.*;
class Main{
    public static void main(String []args)  
    {  
        int p, q, cnt=0, i, dif;  
        Scanner scanner = new Scanner(System.in);
        
        p = scanner.nextInt();
        q = scanner.nextInt();

        int jump [] = new int[q];  
        for(i=0; i<q; i++) 
            jump[i] = scanner.nextInt(); 
        for(i=1; i<q; i++)  
        {  
            if(jump[i]>jump[i-1])  
             dif = (jump[i] - jump[i-1]);  
            else  
             dif = (jump[i-1] - jump[i]);  
            if(dif<=p)  
                cnt++;  
        }  
        if(cnt== q-1)  
            System.out.printf("YOU WIN\n");  
        else  
            System.out.printf("GAME OVER\n");  

    }  
}
